#include <iostream>
#include <vector>
#include <set>

int main() { 
    int problemN;
    std::vector<int> readVec(std::set<int> * );
    int LCIS(std::vector<int> v1, std::vector<int> v2);
    std::cin >> problemN;
    getchar();
    if (problemN  == 1) {
        std::vector<int> vec;  
        int temp;
        int i = 0;
        std::vector<int> listSize;
        std::vector<int> listNumber;
        int seq = 0;
        int max = 1;
        while (std::cin >> temp) {
            vec.push_back(temp);
            listNumber.push_back(1);
            listSize.push_back(1);;
            for (int j = 0; j < i; j++) {
                if (vec[i] > vec[j]) {
                    if (listSize[i] < listSize[j] + 1) {
                        listSize[i] = listSize[j] + 1;
                        listNumber[i] = listNumber[j];
                    }
                    else if (listSize[i] == listSize[j] + 1) {
                        listNumber[i] += listNumber[j];
                    }
                }
            }
            if (listSize[i] > max) {
                max = listSize[i];
                seq = listNumber[i];
            }
            else if (listSize[i] == max) {
                seq += listNumber[i];
            }
            i++;
        }
        for (int el : listNumber) {
            std::cout << el << std::endl;
        }
        std::cout << max << " " << seq << std::endl;
    } else if (problemN == 2) {
        std::vector<int> vec1, vec2;
        std::set<int> s;
        vec1 = readVec(&s);
        int temp;
        while (std::cin >> temp)
        {
            if (s.find(temp) != s.end()) {
                vec2.push_back(temp);
            }
        }
        std::cout << LCIS(vec1, vec2) << std::endl;
    }
    return 0;
}

int LCIS(std::vector<int> v1, std::vector<int> v2) {
    int n1 = v1.size(), n2 = v2.size(), m, n;
    if (n1 < n2) {
        m = n1;
        n = n2;
        std::vector<int> temp = v1;
        v1 = v2;
        v2 = temp;
    }
    else {
        m = n2;
        n = n1;
    }
    std::vector<int> table(m,0);int result = 0;
    for (int i = 0; i < n; i++) {
        int current = 0;
        for (int j = 0; j < m; j++) {
            if (v1[i] == v2[j])
                if (current + 1 > table[j])
                    table[j] = current + 1;

            if (v1[i] > v2[j])
                if (table[j] > current)
                    current = table[j];
            if (table[j] > result)
            result = table[j];
        }
    }

    
    

    return result;
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
     
} //csdasdadasd

