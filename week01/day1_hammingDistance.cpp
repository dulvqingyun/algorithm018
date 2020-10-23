    int hammingDistance(int x, int y) {
        int z = x^y;
        int result=0;
        while(z!=0)
        {
            result+=z%2;
            z= z/2;
        }
        return result;

    }