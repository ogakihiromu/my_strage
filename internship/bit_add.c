int bit_add(int err){
    int msk = 1;
    int cnt = 0;
    int ret = 0;
    while(cnt < 16){
        ret += msk & (err << cnt);
        cnt++;
    }
    return ret;
}

void strcpy(void *p,void *str);
void itoa(char *str,int n);

int bit_print(int err){
    int LCD;
    char cnt[2];
    itoa(cnt,bit_add(err));

    strcpy((void *)LCD,(void *)"***");
    strcpy((void *)(LCD + 5),(void *)cnt);
    strcpy((void *)(LCD + 6),(void *)"***");
}

int err_print(int err){
    int LCD;
    int cnt = 0;
    char text_tmp[2];
    int err_cnt = 0;
    int msk = 1;
    while(cnt < 16){
        if(err & (msk << cnt)){
            err_cnt++;
            cnt++;
            strcpy((void *)(LCD + 3*err_cnt),(void *)"***");
            itoa(text_tmp,cnt);
            strcpy((void *)(LCD + 3*err_cnt + 2),(void *)text_tmp);
        }
        else{
            cnt++;
        }
    }
    
}