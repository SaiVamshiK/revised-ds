class Solution {
public:
    void func(vector<vector<int>> &image,int n,int m,int i,int j,int elem,int newColor)
    {
        image[i][j]=newColor;
        if((i+1<n)&&(image[i+1][j]==elem))
        {
            func(image,n,m,i+1,j,elem,newColor);
        }
        if((j+1<m)&&(image[i][j+1]==elem))
        {
            func(image,n,m,i,j+1,elem,newColor);
        }
        if((i-1>=0)&&(image[i-1][j]==elem))
        {
            func(image,n,m,i-1,j,elem,newColor);
        }
        if((j-1>=0)&&(image[i][j-1]==elem))
        {
            func(image,n,m,i,j-1,elem,newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int elem=image[sr][sc];
        if(newColor==elem)
        {
            return image;
        }
        func(image,image.size(),image[0].size(),sr,sc,elem,newColor);
        return image;
    }
};
