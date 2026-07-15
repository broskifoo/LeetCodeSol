class Solution {
public:

    int rows , cols;

    void dfs(vector<vector<int>>& image, int i , int j , int originalColour , int newColour){
        if ( i<0 || i>=rows || j<0 || j>=cols || image[i][j] != originalColour){
            return;
        }

        image[i][j] = newColour;

        dfs(image, i-1 ,j , originalColour , newColour );
        dfs(image, i+1 ,j , originalColour , newColour );
        dfs(image, i ,j-1 , originalColour , newColour );
        dfs(image, i ,j+1 , originalColour , newColour );
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        rows = image.size();
        cols = image[0].size();

        int originalColour = image[sr][sc];

        if(originalColour == color){
            return image;
        }

        dfs(image ,sr,sc ,originalColour , color);

        return image;
        
    }
};