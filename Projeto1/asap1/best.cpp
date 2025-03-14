#include <iostream>
#include <vector>
#include <set>

int sizeCommonIncSubSeq(std::vector<int>, std::vector<int>);
std::vector<int> readVec(std::set<int> *);
void incSubSeq(int, std::vector<int>, int, int);

int main() {
    short problemN;
    if(scanf("%hd", &problemN) != 1)
        exit(1);
    getchar();
    if (problemN == 1) {
        std::vector<int> vec;
        int temp, size = 0;
        while (scanf("%d", &temp) != EOF){
            vec.push_back(temp);
            size++;
        }
        incSubSeq(size, vec, 1, 1);
    } else if (problemN == 2) {
        std::vector<int> vec1, vec2;
        std::set<int> s;
        vec1 = readVec(&s);
        int temp;
        while (std::cin >> temp)
            if (s.find(temp) != s.end())
                vec2.push_back(temp);
        printf("%d\n", sizeCommonIncSubSeq(vec1, vec2));
    }
    return 0;
}

int sizeCommonIncSubSeq(std::vector<int> v1, std::vector<int> v2) {
    int size1 = v1.size(), size2 = v2.size(), col, row, biggest = 0, con;
    if (size1 < size2) {
        col = size1;
        row = size2;
        std::vector<int> temp = v1;
        v1 = v2;
        v2 = temp;
    } else {
        col = size2;
        row = size1;
    }
    std::vector<int> vec(col,0);
    for (int i = 0; i < row; i++) {
        con = 0;
        for (int j = 0; j < col; j++) {
            if (v1[i] == v2[j]){
                if (vec[j] < con + 1)
                    vec[j] = con + 1;
            } else if (v1[i] > v2[j])
                if (con < vec[j])
                    con = vec[j];
        }
    }
    for(int i = 0; i < col; i++)
        if (vec[i] > biggest)
            biggest = vec[i];
    return biggest;
}

std::vector<int> readVec(std::set<int>  * s) {
    char c = std::getchar();
    int n = 0;
    std::set<int> temp;
    std::vector<int> vec;
    while (c != EOF && c!='\n') {
        if (c != ' ')
            n = n * 10 + c - '0';
        else {
            vec.push_back(n);
            temp.insert(n);
            n = 0;
        }
        c = std::getchar();
    }
    vec.push_back(n);
    temp.insert(n);
    *s = temp;
    return vec;
}

void incSubSeq(int size, std::vector<int> vec, int max, int seq){
    std::vector<int> listNumber(size, 1), listSize(size, 1);
    for (int i = 1; i < size; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (vec[i] > vec[j])
            {
                if (listSize[i] < listSize[j] + 1)
                {
                    listSize[i] = listSize[j] + 1;
                    listNumber[i] = listNumber[j];
                }
                else if (listSize[i] == listSize[j] + 1)
                    listNumber[i] += listNumber[j];
            }
        }
        if (listSize[i] > max)
        {
            max = listSize[i];
            seq = listNumber[i];
        }
        else if (listSize[i] == max)
            seq += listNumber[i];
    }
    printf("%d %d\n", max, seq);
}