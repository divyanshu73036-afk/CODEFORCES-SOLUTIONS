class Solution {
public:
    int countCollisions(string directions) {
        stack<char>st;
        st.push(directions[0]);
        int col=0;
        for(int i=1;i<directions.size();i++){
            if (st.top() == 'R' && directions[i] == 'L') {
                col += 2;
                st.pop();

                // Change: handle consecutive R cars
                while (!st.empty() && st.top() == 'R') {
                    col++;
                    st.pop();
                }

                st.push('S');
            }

           else if (st.top() == 'S' && directions[i] == 'L') {
                col++;
                // S remains stationary
            }

            else if (st.top() == 'R' && directions[i] == 'S') {
                // Change: handle consecutive R cars
                while (!st.empty() && st.top() == 'R') {
                    col++;
                    st.pop();
                }

                st.push('S');
            }

            else {
                st.push(directions[i]);
            }
        }
        return col;

    }
};