 int minMutation(string startGene, string endGene, vector<string>& bank) {
// We have to make a string to another string.
// For this kind of question the BFS approach is most suited.

// Step 1. intialize the set to search faster in the bank, queue for BFS.

unordered_set<string>bankSet(bank.begin(),bank.end());
unordered_set<string>visited; //To check wheather we have seen the element or not.
queue<string>que;

que.push(startGene);
visited.insert(startGene);

int level = 0;
//Step.2 Start the BFS call
//Now try to change each character by "A,C,G,T" and check if it is valid in bankSet;

while (!que.empty())
{
    int size = que.size();

    while(size--)// Iterate all the levels and check if we got the endGene
    {
        string curr = que.front();
        que.pop();
        
        if(curr == endGene)
            return level;
        
        for(char ch : "ACGT")
        {
            string convertedString = curr; // initilize it with curr and change the values

            for(int i = 0 ;i<curr.size();i++)
            {
                convertedString[i] = ch;

                if(bankSet.find(convertedString) != bankSet.end() && visited.find(convertedString) == visited.end())// Checking Valid conditions and we have not encountered it before
                {
                    que.push(convertedString);
                    visited.insert(convertedString);
                }
            }
        }
    }
    level++;
}
return -1; // if it is not possible.


}