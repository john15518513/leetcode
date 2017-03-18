// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        curIndex = 0;
        while ( curIndex < n ) {
            if (buffPtr == 0) cnt = read4(read4Buf);
            if (cnt == 0) break;
            while (curIndex < n && buffPtr < cnt) {
                buf[curIndex++] = read4Buf[buffPtr++];
            }
            if (buffPtr == cnt) buffPtr =0;
        }
        return curIndex;
    }
    char read4Buf[4];
    int curIndex;
    int cnt = 0;
    int buffPtr = 0;
};
