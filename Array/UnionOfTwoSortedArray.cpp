
//logic:- here we get two arr we have to find union so we use two pointer i &j
//i is for first array and j is for second array, if i is smaller than j & not equall to previous num then we print the element of first array and increment i
// same for j, if j is smaller than i & not equal to previous num then we print the element of after that if number is remains then we add up to the final array

// a = [1 2 3 4 5 6 7]
// b = [1 2 5 8 9 10 11]

class Solution{
    public:
     vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n1 = a.size();
        int n2 = b.size();
        int i=0;
        int j=0;
        int vector<int> k;

        while(i<n1 && j<n2){
            if(a[i]<=b[j]){
                if(k.size() ==0 || k.back() != a[i]){
                    k.push_back(a[i]);
                }
                i++;
            }
            else{
                if(k.size() == 0 || k.back()!=b[j]){
                    k.push_back = b[j];
                }
                j++;
            }
        }
        //for remaining Element in Array
        while(j<n2){
            if(k.size() == 0 || k.back() != b[j]){
                k.push_back(b[j]);
            }
            j++;
            
        }
        while(i<n1){
            if(k.size()==0 || k.back() != a[i]){
                k.push_back(a[i]);
            }
            i++;
        }
        return k;

     }
};