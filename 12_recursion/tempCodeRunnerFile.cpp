int number(int n){
    if (n < 1) return;
    return number(n-1);
}