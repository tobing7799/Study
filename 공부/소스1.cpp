#define MAX_STATION 398
// ㄴ 지하철 역 갯수
#include "Graph.h"

int main()
{
	Graph test; // 그래프 선언

	test.Subway("subway.txt", MAX_STATION); // 지하철 경로 찾기 프로그램 시작!

	return 0; // 끝
}