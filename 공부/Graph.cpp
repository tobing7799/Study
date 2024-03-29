#include "Graph.h"


int Graph::Choose(bool t) // 최소인 버텍스의 인덱스를 반환
{
    int min = 99999, min_transfer = 9999, pos = -1;

    if (t) // 최단시간 경로일떄 
    {

        for (int i = 0; i < n; i++)
        {
            if (route[i] < 0)
            {
                if (graph[i].time < min) // 시간이 덜드는 버텍스를 선택
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
    else // 최소환승 경로일때
    {

        for (int i = 0; i < n; i++)
        {
            if (route[i] < 0)
            {
                if (graph[i].transfer < min_transfer) // 환승 횟수가 작은 버텍스를 선택
                {
                    min = graph[i].time;
                    min_transfer = graph[i].transfer;
                    pos = i;
                }
                else if (graph[i].transfer == min_transfer) // 환승 횟수가 같으면
                {
                    if (graph[i].time < min) // 시간이 덜드는 버텍스를 선택
                    {
                        min = graph[i].time;
                        min_transfer = graph[i].transfer;
                        pos = i;
                    }
                }
            }
        }

    }
    return pos; // 인덱스 반환
}

void Graph::DijkstraAlgorithm(int start, bool t) // Dijskstra Algorithm 
{
    int minpos;


    // 그래프와 route배열 초기화
    for (int i = 0; i < n; i++)
    {
        route[i] = -1;
        graph[i].id = -1;
        graph[i].time = 99999;
        graph[i].transfer = 9999;
    }

    // 시작점과 연결된 버텍스에 엣지의 코스트를 대입
    for (Edge* p = graph[start].next; p != NULL; p = p->next)
    {

        if (station[start] == station[p->id]) // 시작점과 연결된 버텍스가 환승역일때
         // 출발역이 환승역인 경우는 환승 횟수와 시간을 0으로 따져야 한다.
        {
            graph[p->id].time = 0;
            graph[p->id].transfer = 0;
        }
        else // 일반적인 경우
        {
            graph[p->id].time = p->time;
            graph[p->id].transfer = p->transfer;
        }
    }


    // 출발역이 환승역인 경우. 출발역과 같은 이름을 가진 역 번호를 가진 엣지들의 값을 모두 0으로 만들어줘야한다
    // bug fix.. (환승역 -> 환승역 경로찾기시 경로 찾기 실패)
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


    // 시작점을 클라우드에 포함시킨다
    //route[start] = start;
    route[start] = 0;
    // 시작점 초기화
    graph[start].time = 0;
    graph[start].transfer = 0;


    for (int i = 0, prev = start; i < n - 2; i++)
    {
        // 최소인 버텍스 선택
        minpos = this->Choose(t);

        //route[minpos] = prev;

        // 최소인 버텍스 클라우드에 포함시킨다
        route[minpos] = 0;

        // 선택된 버텍스에 연결된 엣지들로 다른 버텍스의 값을 업데이트시킨다 
        for (Edge* p = graph[minpos].next; p != NULL; p = p->next)
        {
            if (t) // 최단시간 경로일때
            {
                if (graph[minpos].time + p->time < graph[p->id].time) // 시간을 비교하여 업데이트
                {
                    graph[p->id].time = graph[minpos].time + p->time;
                    graph[p->id].transfer = graph[minpos].transfer + p->transfer;
                }
                else if (graph[minpos].time + p->time == graph[p->id].time) // 시간이 같을때.. 환승횟수가 적은게 좋겠죠?(상식..ㅠ)
                {
                    if (graph[minpos].transfer + p->transfer < graph[p->id].transfer) // 환승횟수를 비교
                    {
                        graph[p->id].time = graph[minpos].time + p->time;
                        graph[p->id].transfer = graph[minpos].transfer + p->transfer;
                    }
                }
            }
            else // 최소환승 경로일때
            {
                if (graph[minpos].transfer + p->transfer < graph[p->id].transfer) // 환승횟수를 비교하여 업데이트
                {
                    graph[p->id].time = graph[minpos].time + p->time;
                    graph[p->id].transfer = graph[minpos].transfer + p->transfer;
                }
                else if (graph[minpos].transfer + p->transfer == graph[p->id].transfer) // 환승횟수가 같으면
                {
                    if (graph[minpos].time + p->time < graph[p->id].time) // 시간을 비교
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
    string t; // 임시 스트링 변수
    stack<int> s, r; // 스택 s,r
    Edge* temp; // 임시 엣지포인터 변수
    Edge* p; // 임시 엣지포인터 변수
    n = N; // 지하철 역 갯수 초기화

    // 클래스 데이터 초기화
    graph = new Edge[n];
    station = new string[n];
    route = new int[n];

    file.open(name, ios::in); // 파일 읽기 (ios::in -> 읽기)

    int t1, t2, time;
    string s1, s2;
    while (!file.eof())
    {
        // 임시 변수에 한 줄의 데이터 입력
        file >> t1;
        file >> t2;
        file >> time;
        file >> s1;

        // 버그방지용
        // 파일 마지막 공백문자 같은 엉뚱한 문자가 있을때 멈춘다
        if (file.eof())
            break;

        file >> s2;

        //끝

        // 인덱스에 넣기위해 역 번호에서 1씩 빼준다
        t1 -= 1;
        t2 -= 1;

        // 엣지를 만든다 (1)
        temp = new Edge();
        temp->id = t2;
        temp->time = time;
        if (s1 == s2) temp->transfer = 1;
        else temp->transfer = 0;

        // 서로의 버텍스에 엣지를 연결한다 (1)
        p = &graph[t1];
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;

        // 엣지를 만든다 (2)
        temp = new Edge();
        temp->id = t1;
        temp->time = time;
        if (s1 == s2) temp->transfer = 1;
        else temp->transfer = 0;

        // 서로의 버텍스에 엣지를 연결한다 (2)
        p = &graph[t2];
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;


        // 역 이름 배열에 역 이름을 저장한다
        station[t1] = s1;
        station[t2] = s2;


    }

    file.close();
    //끝-파일입력


    // 출발역,도착역 입력!!!!!!
    while (start == end)
    {

        while (start < 0)
        {
            std::cout << "출발역을 입력하세요...\n : ";
            cin >> t;
            std::cout << std::endl;

            // 출발역 이름과 같은 역번호 아무거나 하나 찾는다
            for (int i = 0; i < n; i++)
            {
                if (station[i] == t)
                {
                    start = i;
                    break;
                }
            }

            //없으면
            if (start < 0)
            {
                std::cout << "잘못 입력하셨습니다." << std::endl;

            }
        }

        while (end < 0)
        {

            std::cout << "도착역을 입력하세요...\n : ";
            cin >> t;
            std::cout << std::endl;


            // 도착역 이름과 같은 역번호 아무거나 하나 찾는다
            for (int i = 0; i < n; i++)
            {
                if (station[i] == t)
                {
                    end = i;
                    break;
                }
            }

            //없으면
            if (end < 0)
            {
                std::cout << "잘못 입력하셨습니다." << std::endl;

            }

        }

        if (start == end)
        {
            std::cout << "출발역과 도착역이 같습니다...." << std::endl;
            start = end = -1;
        }
    }



    std::cout << "찾고자 하는 구간 : " << station[start] << " -> " << station[end] << std::endl << std::endl;
    std::cout << "* 최단시간 경로 :" << std::endl;
    this->DijkstraAlgorithm(start, true); // 알고리즘 실행 (true이므로 최단시간 경로)

    // 도착역 중, 가장 소요시간이 작은 버텍스를 선택한다
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

    // 출발역의 인덱스와 찾은 버텍스의 인덱스로 경로를 스택에 저장한다. 
    this->FindRoute(s, start, end);

    // 스택에서 스택으로 옮긴다 (순서 역순으로 바꾸기)
    while (!s.empty())
    {
        r.push(s.top());
        s.pop();
    }

    // 경로 출력
    for (v = 0, prev = -1; !r.empty(); v++)
    {
        if (prev != -1 && station[prev] == station[r.top()])
        {
            if (station[r.top()] != station[start])
                std::cout << "(환승)";

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
    std::cout << std::endl << "\t-->" << v - 1 << "개역 지남" << std::endl
        << "\t-->" << graph[end].time / 60 << "시간 " << graph[end].time % 60 << "분 걸리고, " << graph[end].transfer << "번 환승합니다." << std::endl;

    std::cout << std::endl;
    std::cout << "* 최소환승 경로 :" << std::endl;
    this->DijkstraAlgorithm(start, false); // 알고리즘 실행 (false- 최소환승경로)

    // 도착역 버텍스 중에 환승횟수가 가장 작은 버텍스를 선택
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

    // 경로찾기
    this->FindRoute(s, start, end);

    // 스택에서 스택으로 옮김
    while (!s.empty())
    {
        r.push(s.top());
        s.pop();
    }

    //출력
    for (v = 0, prev = -1; !r.empty(); v++)
    {
        if (prev != -1 && station[prev] == station[r.top()])
        {
            if (station[r.top()] != station[start])
                std::cout << "(환승)";

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
    std::cout << std::endl << "\t-->" << v - 1 << "개역 지남" << std::endl
        << "\t-->" << graph[end].time / 60 << "시간 " << graph[end].time % 60 << "분 걸리고, " << graph[end].transfer << "번 환승합니다." << std::endl;


}

bool Graph::FindRoute(stack<int>& s, int start, int end) // 완성된 클라우드 에서 경로찾기
{
    s.push(start); // 스택에 넣는다.

    if (start == end) // 시작=끝 일때 경로찾았다고 알려줌 (return true)
        return true;

    for (Edge* p = graph[start].next; p != NULL; p = p->next) // 시작점에 연결된 엣지를 모두 조사한다
    {
        // 시작점버텍스값 + 엣지값 과 엣지로연결된 버텍스의 값이 같으면 (DijkstraAlgorithm에서 클라우드에 포함시킬떄 연결한 경로)
        if (graph[start].time + p->time == graph[p->id].time && graph[start].transfer + p->transfer == graph[p->id].transfer)
        {
            if (!this->FindRoute(s, p->id, end)) // 다음 경로로 이동 했는데 경로가 없다면
            {
                s.pop(); // pop한다
            }
            else // 경로를 찾았으면 pop하지않고 유지
            {
                return true; // 경로를 찾았다고 알려줌
            }
        }
    }
    return false;
}