#include <stdio.h>

int global_static_init_var = 1;
int global_static_uninit_var;

void fun(int i) {
    printf("%d\n", i);
}

int main() {
    static int local_static_init_var = 2;
    static int local_static_uninit_var;
    int local_init_var = 3;
    int local_uninit_var;
    fun(local_static_init_var + local_static_uninit_var + local_init_var + local_uninit_var);
    return local_init_var;
}
