#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {

    int sum[16]={0};
    int a[36];
    static int r=0,x=0;

    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++,r++){
            a[r]=arr[i][j];
        }
    }


    for(int i=0;i<22;i++,x++){
        sum[x]=a[i]+a[i+1]+a[i+2]+a[i+7]+a[i+12]+a[i+13]+a[i+14];
        if(i==3 || i==9 || i==15)
            i+=2;
        cout << sum[x] << " ";
    }

    int large = sum[0];

    for(int i=1;i<16;i++){
        if(large<sum[i])
            large = sum[i];
    }

    return large;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}