class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0, j = 0;
        while (i < version1.length() or j < version2.length()) {
            int v1 = 0, v2 = 0;
            //cout << "hi" << endl;
            while (i < version1.length() and version1[i] != '.') {
                v1 += v1*10+version1[i]-48;
                i++;
            }
            while (j < version2.length() and version2[j] != '.') {
                v2 += v2*10+version2[j]-48;
                j++;
            }
            //cout << v1 << " " << v2;
            if (v2 > v1) return -1;
            if (v1 > v2) return 1;
            i++;
            j++;
        }
        //cout << "je" ;
        return 0;
    }
};
