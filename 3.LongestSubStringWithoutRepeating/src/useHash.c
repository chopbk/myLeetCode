int lengthOfLongestSubstring(char* s) {
    int i = 0,i_start_substring = 0,max = 0,h_index;;
    int n = 128; /*num member of hash array*/
    int *h_arr = (int *) malloc (n*sizeof(int)) ;
    memset(h_arr, -1, n*sizeof(h_arr[0])); 
    while(*(s+i)!=NULL)
    {
        h_index = *(s+i); /*get index of hash arrar*/
        /*i_start_substring is started index 0 of substring*/
        if(h_arr[h_index] >= i_start_substring) 
        /*if h_arr[h_index] != -1 and > i_start_substring,
        get new i_start_substring*/
        {
            i_start_substring = h_arr[h_index]+1;
        }
        h_arr[h_index] = i;
        max = (max < (i-i_start_substring+1))?i-i_start_substring+1:max;
        i++;
    }
    free(h_arr);
    return max;
}