#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size());
    map<char, int> map;
    for (int i = 0; i < keymap.size(); ++i)
    {
        for (int j = 0; j < keymap[i].size(); ++j)
        {
            if (map[keymap[i][j]])
            {
                if (map[keymap[i][j]] > j + 1)
                {
                    map[keymap[i][j]] = j + 1;
                }
            }
            else
            {
                map[keymap[i][j]] = j + 1;
            }
        }
    }

    for(int i=0; i<targets.size(); ++i)
    {
        for (char c : targets[i]) {
            if (map[c])
            {
                answer[i] += map[c];
            }
            else
            {
                answer[i] = -1;
                break;
            }
        }
    }
    return answer;
}

int main()
{
    for (int n : solution({"ABACD","BCEFD" }, {"ABCD","AABB"})) {
        cout << n << " ";
    }
}