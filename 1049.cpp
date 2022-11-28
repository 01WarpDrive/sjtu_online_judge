#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;



char result_data[50] = { 0 };
int data_size = 0;

void CreateTree(int root_num, char* temp_data1, char* temp_data2) {
    if (strlen(temp_data1) == 0) return;

    char root = temp_data1[0];
    result_data[root_num] = root;
    data_size = max(root_num, data_size);
    char ldata1[50] = { 0 };
    char rdata1[50] = { 0 };
    char ldata2[50] = { 0 };
    char rdata2[50] = { 0 };
    bool flag = false;

    for (int i = 0, k = 0; i < strlen(temp_data1); i++, k++) {
        if (temp_data2[i] == root) {
            flag = true;
            k = -1;
        }
        else if (!flag) {
            ldata1[k] = temp_data1[i + 1];
            ldata2[k] = temp_data2[i];
        }
        else {
            rdata1[k] = temp_data1[i];
            rdata2[k] = temp_data2[i];
        }
    }

    CreateTree(root_num * 2, ldata1, ldata2);
    CreateTree(root_num * 2 + 1, rdata1, rdata2);
}


int main() {
    char preData[50], postData[50];
    cin >> preData >> postData;

    CreateTree(1, preData, postData);

    //输出
    cout << result_data[1];
    for (int i = 2; i <= data_size; i++) {
        if (result_data[i] == 0)
            cout << " NULL";
        else
            cout << " " << result_data[i];
    }

    return 0;
}
