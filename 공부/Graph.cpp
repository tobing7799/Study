#include "Graph.h"


int Graph::Choose(bool t) // �ּ��� ���ؽ��� �ε����� ��ȯ
{
    int min = 99999, min_transfer = 9999, pos = -1;

    if (t) // �ִܽð� ����ϋ� 
    {

        for (int i = 0; i < n; i++)
        {
            if (route[i] < 0)
            {
                if (graph[i].time < min) // �ð��� ����� ���ؽ��� ����
                {
                    min = graph[i].time;
                    min_transfer = graph[i].transfer;
                    pos = i;
                }
                else if (graph[i].time == min)
                {
                    if (graph[i].transfer < min_transfer)
                    {
                        min = graph[i].time;
                        min_transfer = graph[i].transfer;
                        pos = i;
                    }
                }
            }
        }

    }
    else // �ּ�ȯ�� ����϶�
    {

        for (int i = 0; i < n; i++)
        {
            if (route[i] < 0)
            {
                if (graph[i].transfer < min_transfer) // ȯ�� Ƚ���� ���� ���ؽ��� ����
                {
                    min = graph[i].time;
                    min_transfer = graph[i].transfer;
                    pos = i;
                }
                else if (graph[i].transfer == min_transfer) // ȯ�� Ƚ���� ������
                {
                    if (graph[i].time < min) // �ð��� ����� ���ؽ��� ����
                    {
                        min = graph[i].time;
                        min_transfer = graph[i].transfer;
                        pos = i;
                    }
                }
            }
        }

    }
    return pos; // �ε��� ��ȯ
}

void Graph::DijkstraAlgorithm(int start, bool t) // Dijskstra Algorithm 
{
    int minpos;


    // �׷����� route�迭 �ʱ�ȭ
    for (int i = 0; i < n; i++)
    {
        route[i] = -1;
        graph[i].id = -1;
        graph[i].time = 99999;
        graph[i].transfer = 9999;
    }

    // �������� ����� ���ؽ��� ������ �ڽ�Ʈ�� ����
    for (Edge* p = graph[start].next; p != NULL; p = p->next)
    {

        if (station[start] == station[p->id]) // �������� ����� ���ؽ��� ȯ�¿��϶�
         // ��߿��� ȯ�¿��� ���� ȯ�� Ƚ���� �ð��� 0���� ������ �Ѵ�.
        {
            graph[p->id].time = 0;
            graph[p->id].transfer = 0;
        }
        else // �Ϲ����� ���
        {
            graph[p->id].time = p->time;
            graph[p->id].transfer = p->transfer;
        }
    }


    // ��߿��� ȯ�¿��� ���. ��߿��� ���� �̸��� ���� �� ��ȣ�� ���� �������� ���� ��� 0���� ���������Ѵ�
    // bug fix.. (ȯ�¿� -> ȯ�¿� ���ã��� ��� ã�� ����)
    for (int i = 0; i < n; i++)
    {
        if (station[start] == station[i])
        {
            for (Edge* p = graph[i].next; p != NULL; p = p->next)
            {
                if (station[i] == station[p->id])
                {
                    p->time = 0;
                    p->transfer = 0;
                }
            }
        }
    }


    // �������� Ŭ���忡 ���Խ�Ų��
    //route[start] = start;
    route[start] = 0;
    // ������ �ʱ�ȭ
    graph[start].time = 0;
    graph[start].transfer = 0;


    for (int i = 0, prev = start; i < n - 2; i++)
    {
        // �ּ��� ���ؽ� ����
        minpos = this->Choose(t);

        //route[minpos] = prev;

        // �ּ��� ���ؽ� Ŭ���忡 ���Խ�Ų��
        route[minpos] = 0;

        // ���õ� ���ؽ��� ����� ������� �ٸ� ���ؽ��� ���� ������Ʈ��Ų�� 
        for (Edge* p = graph[minpos].next; p != NULL; p = p->next)
        {
            if (t) // �ִܽð� ����϶�
            {
                if (graph[minpos].time + p->time < graph[p->id].time) // �ð��� ���Ͽ� ������Ʈ
                {
                    graph[p->id].time = graph[minpos].time + p->time;
                    graph[p->id].transfer = graph[minpos].transfer + p->transfer;
                }
                else if (graph[minpos].time + p->time == graph[p->id].time) // �ð��� ������.. ȯ��Ƚ���� ������ ������?(���..��)
                {
                    if (graph[minpos].transfer + p->transfer < graph[p->id].transfer) // ȯ��Ƚ���� ��
                    {
                        graph[p->id].time = graph[minpos].time + p->time;
                        graph[p->id].transfer = graph[minpos].transfer + p->transfer;
                    }
                }
            }
            else // �ּ�ȯ�� ����϶�
            {
                if (graph[minpos].transfer + p->transfer < graph[p->id].transfer) // ȯ��Ƚ���� ���Ͽ� ������Ʈ
                {
                    graph[p->id].time = graph[minpos].time + p->time;
                    graph[p->id].transfer = graph[minpos].transfer + p->transfer;
                }
                else if (graph[minpos].transfer + p->transfer == graph[p->id].transfer) // ȯ��Ƚ���� ������
                {
                    if (graph[minpos].time + p->time < graph[p->id].time) // �ð��� ��
                    {
                        graph[p->id].time = graph[minpos].time + p->time;
                        graph[p->id].transfer = graph[minpos].transfer + p->transfer;
                    }
                }
            }

        }

        //prev = minpos;

    }

}

void Graph::Subway(const char* name, int N)
{

    int start = -1, end = -1;
    int min, v, prev;
    string t; // �ӽ� ��Ʈ�� ����
    stack<int> s, r; // ���� s,r
    Edge* temp; // �ӽ� ���������� ����
    Edge* p; // �ӽ� ���������� ����
    n = N; // ����ö �� ���� �ʱ�ȭ

    // Ŭ���� ������ �ʱ�ȭ
    graph = new Edge[n];
    station = new string[n];
    route = new int[n];

    file.open(name, ios::in); // ���� �б� (ios::in -> �б�)

    int t1, t2, time;
    string s1, s2;
    while (!file.eof())
    {
        // �ӽ� ������ �� ���� ������ �Է�
        file >> t1;
        file >> t2;
        file >> time;
        file >> s1;

        // ���׹�����
        // ���� ������ ���鹮�� ���� ������ ���ڰ� ������ �����
        if (file.eof())
            break;

        file >> s2;

        //��

        // �ε����� �ֱ����� �� ��ȣ���� 1�� ���ش�
        t1 -= 1;
        t2 -= 1;

        // ������ ����� (1)
        temp = new Edge();
        temp->id = t2;
        temp->time = time;
        if (s1 == s2) temp->transfer = 1;
        else temp->transfer = 0;

        // ������ ���ؽ��� ������ �����Ѵ� (1)
        p = &graph[t1];
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;

        // ������ ����� (2)
        temp = new Edge();
        temp->id = t1;
        temp->time = time;
        if (s1 == s2) temp->transfer = 1;
        else temp->transfer = 0;

        // ������ ���ؽ��� ������ �����Ѵ� (2)
        p = &graph[t2];
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;


        // �� �̸� �迭�� �� �̸��� �����Ѵ�
        station[t1] = s1;
        station[t2] = s2;


    }

    file.close();
    //��-�����Է�


    // ��߿�,������ �Է�!!!!!!
    while (start == end)
    {

        while (start < 0)
        {
            std::cout << "��߿��� �Է��ϼ���...\n : ";
            cin >> t;
            std::cout << std::endl;

            // ��߿� �̸��� ���� ����ȣ �ƹ��ų� �ϳ� ã�´�
            for (int i = 0; i < n; i++)
            {
                if (station[i] == t)
                {
                    start = i;
                    break;
                }
            }

            //������
            if (start < 0)
            {
                std::cout << "�߸� �Է��ϼ̽��ϴ�." << std::endl;

            }
        }

        while (end < 0)
        {

            std::cout << "�������� �Է��ϼ���...\n : ";
            cin >> t;
            std::cout << std::endl;


            // ������ �̸��� ���� ����ȣ �ƹ��ų� �ϳ� ã�´�
            for (int i = 0; i < n; i++)
            {
                if (station[i] == t)
                {
                    end = i;
                    break;
                }
            }

            //������
            if (end < 0)
            {
                std::cout << "�߸� �Է��ϼ̽��ϴ�." << std::endl;

            }

        }

        if (start == end)
        {
            std::cout << "��߿��� �������� �����ϴ�...." << std::endl;
            start = end = -1;
        }
    }



    std::cout << "ã���� �ϴ� ���� : " << station[start] << " -> " << station[end] << std::endl << std::endl;
    std::cout << "* �ִܽð� ��� :" << std::endl;
    this->DijkstraAlgorithm(start, true); // �˰��� ���� (true�̹Ƿ� �ִܽð� ���)

    // ������ ��, ���� �ҿ�ð��� ���� ���ؽ��� �����Ѵ�
    min = graph[end].time;
    for (int i = 0; i < n; i++)
    {
        if (station[end] == station[i])
        {
            if (graph[i].time < min)
            {
                min = graph[i].time;
                end = i;
            }
        }
    }

    // ��߿��� �ε����� ã�� ���ؽ��� �ε����� ��θ� ���ÿ� �����Ѵ�. 
    this->FindRoute(s, start, end);

    // ���ÿ��� �������� �ű�� (���� �������� �ٲٱ�)
    while (!s.empty())
    {
        r.push(s.top());
        s.pop();
    }

    // ��� ���
    for (v = 0, prev = -1; !r.empty(); v++)
    {
        if (prev != -1 && station[prev] == station[r.top()])
        {
            if (station[r.top()] != station[start])
                std::cout << "(ȯ��)";

            v--;
            prev = r.top();
            r.pop();
        }
        else
        {
            if (v != 0)
                std::cout << " -> ";
            else
                std::cout << " ";

            std::cout << station[r.top()];
            prev = r.top();
            r.pop();

        }
    }
    std::cout << std::endl << "\t-->" << v - 1 << "���� ����" << std::endl
        << "\t-->" << graph[end].time / 60 << "�ð� " << graph[end].time % 60 << "�� �ɸ���, " << graph[end].transfer << "�� ȯ���մϴ�." << std::endl;

    std::cout << std::endl;
    std::cout << "* �ּ�ȯ�� ��� :" << std::endl;
    this->DijkstraAlgorithm(start, false); // �˰��� ���� (false- �ּ�ȯ�°��)

    // ������ ���ؽ� �߿� ȯ��Ƚ���� ���� ���� ���ؽ��� ����
    min = graph[end].transfer;
    for (int i = 0; i < n; i++)
    {
        if (station[end] == station[i])
        {
            if (graph[i].transfer < min)
            {
                min = graph[i].transfer;
                end = i;
            }
        }
    }

    // ���ã��
    this->FindRoute(s, start, end);

    // ���ÿ��� �������� �ű�
    while (!s.empty())
    {
        r.push(s.top());
        s.pop();
    }

    //���
    for (v = 0, prev = -1; !r.empty(); v++)
    {
        if (prev != -1 && station[prev] == station[r.top()])
        {
            if (station[r.top()] != station[start])
                std::cout << "(ȯ��)";

            v--;
            prev = r.top();
            r.pop();
        }
        else
        {
            if (v != 0)
                std::cout << " -> ";
            else
                std::cout << " ";

            std::cout << station[r.top()];
            prev = r.top();
            r.pop();
        }
    }
    std::cout << std::endl << "\t-->" << v - 1 << "���� ����" << std::endl
        << "\t-->" << graph[end].time / 60 << "�ð� " << graph[end].time % 60 << "�� �ɸ���, " << graph[end].transfer << "�� ȯ���մϴ�." << std::endl;


}

bool Graph::FindRoute(stack<int>& s, int start, int end) // �ϼ��� Ŭ���� ���� ���ã��
{
    s.push(start); // ���ÿ� �ִ´�.

    if (start == end) // ����=�� �϶� ���ã�Ҵٰ� �˷��� (return true)
        return true;

    for (Edge* p = graph[start].next; p != NULL; p = p->next) // �������� ����� ������ ��� �����Ѵ�
    {
        // ���������ؽ��� + ������ �� �����ο���� ���ؽ��� ���� ������ (DijkstraAlgorithm���� Ŭ���忡 ���Խ�ų�� ������ ���)
        if (graph[start].time + p->time == graph[p->id].time && graph[start].transfer + p->transfer == graph[p->id].transfer)
        {
            if (!this->FindRoute(s, p->id, end)) // ���� ��η� �̵� �ߴµ� ��ΰ� ���ٸ�
            {
                s.pop(); // pop�Ѵ�
            }
            else // ��θ� ã������ pop�����ʰ� ����
            {
                return true; // ��θ� ã�Ҵٰ� �˷���
            }
        }
    }
    return false;
}