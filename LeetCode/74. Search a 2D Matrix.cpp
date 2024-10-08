bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
        int n = matrix.size(); // rows
        int m = matrix[0].size(); // columns

        int low = 0 ; 
        int high = (n*m) - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2 ; 
            int rowNo = mid / m;
            int colNo = mid % m ;

            if(matrix[rowNo][colNo] == target)
            {
                return true;
            }
            else if(matrix[rowNo][colNo] < target)
            {
                low = mid + 1;
            }
            else // matrix[rowNo][colNo] > target
            {
                high = mid-1; // this high should be changed always if we did'nt find the element
            }
        }
        return false;

}
Time Complexity: O(log(NxM)), where N = given row number, M = given column number.
Reason: We are applying binary search on the imaginary 1D array of size NxM.

Space Complexity: O(1) as we are not using any extra space.
