/*
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Server
{
private:
    int id;
    int ram;
    float cpu;
    int x;
    int y;

public:
    Server()
    {
        id = 0;
        ram = 0;
        cpu = 0;
        x = 0;
        y = 0;
    }
    Server(int id, int ram, float cpu, int x, int y)
    {
        this->id = id;
        this->ram = ram;
        this->cpu = cpu;
        this->x = x;
        this->y = y;
    }

    int getId()
    {
        return id;
    }

    int getRam()
    {
        return ram;
    }

    float getCpu()
    {
        return cpu;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }
};

class LoadBalancer
{
protected:
    int id;
    int type;
    int x;
    int y;
    vector<Server*> servers;

public:
    LoadBalancer(int id, int type, int x, int y)
    {
        this->id = id;
        this->type = type;
        this->x = x;
        this->y = y;
    }

    virtual void addServer(Server* server) = 0;
    virtual Server* getServer() = 0;

    int getId()
    {
        return id;
    }

    int getType()
    {
        return type;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }
};

class RoundRoundRoninLoadBalancer : public LoadBalancer
{
private:
    int currentIndex;

public:
    RoundRoundRoninLoadBalancer(int id, int type, int x, int y)
        : LoadBalancer(id, type, x, y), currentIndex(0) {}

    void addServer(Server* server)
    {
        servers.push_back(server);
    }

    Server* getServer()
    {
        if (servers.empty())
            return nullptr;

        Server* server = servers[currentIndex];
        currentIndex = (currentIndex + 1) % servers.size();
        return server;
    }
};

class WeightedRoundRoundRoninLoadBalancer : public LoadBalancer
{
public:
    WeightedRoundRoundRoninLoadBalancer(int id, int type, int x, int y)
        : LoadBalancer(id, type, x, y) {}

    void addServer(Server* server)
    {
        servers.push_back(server);
    }

    Server* getServer()
    {
        if (servers.empty())
            return nullptr;

        Server* selectedServer = servers[0];
        float minDiff = abs(selectedServer->getRam() * selectedServer->getCpu() - getX() * getY());

        for (Server* server : servers)
        {
            float diff = abs(server->getRam() * server->getCpu() - getX() * getY());
            if (diff < minDiff)
            {
                selectedServer = server;
                minDiff = diff;
            }
        }

        return selectedServer;
    }
};

class FastestResponseTimeLoadBalancer : public LoadBalancer
{
public:
    FastestResponseTimeLoadBalancer(int id, int type, int x, int y)
        : LoadBalancer(id, type, x, y) {}

    void addServer(Server* server)
    {
        servers.push_back(server);
    }

    Server* getServer()
    {
        if (servers.empty())
            return nullptr;

        Server* selectedServer = servers[0];
        float minTime = sqrt(pow(getX(), 2) + pow(getY(), 2)) / servers[0]->getCpu();

        for (Server* server : servers)
        {
            float time = sqrt(pow(server->getX() - getX(), 2) + pow(server->getY() - getY(), 2)) / server->getCpu();
            if (time < minTime)
            {
                selectedServer = server;
                minTime = time;
            }
        }

        return selectedServer;
    }
};

class Request
{
private:
    int id;
    float weight;
    int x;
    int y;

public:
    Request(int id, float weight, int x, int y)
    {
        this->id = id;
        this->weight = weight;
        this->x = x;
        this->y = y;
    }

    int getId() const
    {
        return id;
    }

    float getWeight() const
    {
        return weight;
    }

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }
};

int main()
{
    int lbId, lbType, lbX, lbY;
    cin >> lbId >> lbType >> lbX >> lbY;

    int numServers, numLoadBalancers;
    cin >> numServers >> numLoadBalancers;

    vector<Server*> servers;
    for (int i = 0; i < numServers; i++)
    {
        int serverId, ram;
        float cpu;
        int x, y;
        cin >> serverId >> ram >> cpu >> x >> y;
        Server* server = new Server(serverId, ram, cpu, x, y);
        servers.push_back(server);
    }

    vector<LoadBalancer*> subLoadBalancers;
    for (int i = 0; i < numLoadBalancers; i++)
    {
        int subLbId, subLbType, subLbX, subLbY;
        cin >> subLbId >> subLbType >> subLbX >> subLbY;

        LoadBalancer* subLoadBalancer;
        if (subLbType == 1)
        {
            subLoadBalancer = new RoundRoundRoninLoadBalancer(subLbId, subLbType, subLbX, subLbY);
        }
        else if (subLbType == 2)
        {
            subLoadBalancer = new WeightedRoundRoundRoninLoadBalancer(subLbId, subLbType, subLbX, subLbY);
        }
        else if (subLbType == 3)
        {
            subLoadBalancer = new FastestResponseTimeLoadBalancer(subLbId, subLbType, subLbX, subLbY);
        }
        subLoadBalancers.push_back(subLoadBalancer);
    }

    LoadBalancer* loadBalancer;
    if (lbType == 1)
    {
        loadBalancer = new RoundRoundRoninLoadBalancer(lbId, lbType, lbX, lbY);
    }
    else if (lbType == 2)
    {
        loadBalancer = new WeightedRoundRoundRoninLoadBalancer(lbId, lbType, lbX, lbY);
    }
    else if (lbType == 3)
    {
        loadBalancer = new FastestResponseTimeLoadBalancer(lbId, lbType, lbX, lbY);
    }
    else
    {
        loadBalancer = new RoundRoundRoninLoadBalancer(lbId, lbType, lbX, lbY);
    }

    for (Server* server : servers)
    {
        loadBalancer->addServer(server);
    }

    for (LoadBalancer* subLoadBalancer : subLoadBalancers)
    {
        Server* server = new Server(subLoadBalancer->getId(), 0, 0.0, subLoadBalancer->getX(), subLoadBalancer->getY());
        loadBalancer->addServer(server);
        servers.push_back(server);
    }
    int numRequests;
    cin >> numRequests;

    for (int i = 0; i < numRequests; i++)
    {
        int requestId;
        float weight;
        int x, y;
        cin >> requestId >> weight >> x >> y;
        Request request(requestId, weight, x, y);

        LoadBalancer* currentLoadBalancer = loadBalancer;
        Server* selectedServer = nullptr;

        while (selectedServer == nullptr)
        {
            selectedServer = currentLoadBalancer->getServer();

            if (selectedServer == nullptr)
            {
                for (LoadBalancer* subLoadBalancer : subLoadBalancers)
                {
                    if (subLoadBalancer == currentLoadBalancer)
                    {
                        continue;
                    }
                    currentLoadBalancer = subLoadBalancer;
                    break;
                }
            }
        }

        cout << request.getId() << " " << selectedServer->getId() << endl;
    }

    return 0;
}

