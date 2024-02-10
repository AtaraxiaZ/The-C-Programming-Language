
int isupper_space(int a){
    if (a >= 65 && a <= 90){
        return 1;
    } else {
        return 0;
    }
}

int isupper_speed(int a){
    char table[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 26; i++){
        if (a == table[i])
            return 1;
    }
    return 0;
}
