//线性表的插入操作
template <class T>
bool SeqList<T>::Insert(int i, T& x){
    if(last==maxSize-1) return false;
    if(i<0 || i>last+1) return false;
    for(int j = last; j >= i; j--)
        data[j+1] = data[j];
    data[i] = x;
    last++;
    return true;
}

//线性表的删除操作
template <class T>
bool SeqList<T>::Remove(int i, T& x){
    if(last==-1) return false;
    if(i<0 || i>last-1) return false;
    for(int j = i; j <= last; j++)
        data[j-1] = data[j];
    last--;
    return true;
}
