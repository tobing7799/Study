#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <stack> // �ϼ��� Ŭ���忡�� ��Ŀ�ú��Լ��� ��θ� �����Ҷ� ���
#include <iostream>
#include <fstream>
#include <string>// ���̸� Ŭ����
#include <stack>


class Edge // ���� Ŭ����..
{
public:
	int id; // �� ��ȣ
	int time; // �̵��ð�
	int transfer; // ȯ�� Ƚ��
	Edge* next;
	Edge() : next(NULL) {}
};

class Graph // �׷��� Ŭ����..
{
private:
	ofstream outputfile;
	string* station; // �� ��ȣ�� ���� �� �̸�
	Edge* graph; // �׷��� (adjacency list)
	int* route; // ������ Ŭ���忡 ���Ե��� ���� ���ؽ�, ������ �ƴϸ� Ŭ���忡 ���Ե� ���ؽ�
	int n; // ����ö �� ����
public:
	int Choose(bool t); // Ŭ���忡 ���Ե��� ���� ���ؽ� ��, cost�� �ּ��� ���ؽ��� �ε����� ��ȯ. t������ ��Ұ� �޶���
	void DijkstraAlgorithm(int start, bool t); // Dijkstra Algorithm �����κ�
	void Subway(const char* name, int N); // ��߿�,�������� �Է� �ް� Dijkstra Algorithm�� �����Ͽ� �ִܽð�,�ּ�ȯ�� ��θ� �������
	bool FindRoute(stack<int>& s, int start, int end); // Dijkstra Algorithm�� ������ ���� �׷������� ��θ� ���ÿ� �Ű��ִ� ����Լ�
};

#endif