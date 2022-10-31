//1.
#include <iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;
int force( char* s, char* t) {
    for (int i = 0; s[i]; i++) {
        bool flag = true;
        for (int j = 0; t[j]; j++) {
            if (s[i + j] == t[j]) 
                continue;
            flag = false;
            break;
        }
        if (flag) return i;
    }
    return -1;
}
int main() {
    char a[400], b[50];
    cin.getline(a, 400, '\n');
    cin.getline(b, 50, '\n');
    cout<<force(a, b);
    return 0;
    
}




//2.
 #include <iostream>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
using namespace std;
void getnext(char* a, int* next) {
	next[0] = -1;
	int i = 0, j = -1;
	while (i < strlen(a)) {
		if (j == -1 || a[i] == a[j]) {
			i++; 
			j++;
			next[i] = j;
			
		}
		else
		{
			j = next[j];
		}
		
	}
	
}
int main() {
	char a[200];
	int next[200];
	cin.getline(a, 200, '\n');
	getnext(a, next);
	for (int k = 0; k < strlen(a); k++)
		cout << next[k] << " ";
	return 0;
}


//3.
#include <iostream>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
using namespace std;
void  getnext(char* a, int* next) {
	next[0] = -1;
	int i = 0, j = -1;
	while (i < strlen(a)) {
		if (j == -1 || a[i] == a[j]) {
			i++; 
			j++;
			next[i] = j;
			
		}
		else
		{
			j = next[j];
		}
	}
	
}

int kmp( char* t,  char* p) {
	int i = 0;
	int j = 0;
	int* next = (int*)malloc(sizeof(int) * strlen(p));
	int t_len = strlen(t);
	int p_len = strlen(p);
	getnext(p, next);
	while (i < t_len && j < p_len) {
		if (j == -1 || t[i] == p[j]) {
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j == strlen(p))
		return i - j;
	else
		return -1;
}

int main() {
	char a[200];
	char b[200];
	int next[200];
	cin.getline(a, 200, '\n');
	cin.getline(b, 200, '\n');
	getnext(b, next);
	for (int k = 0; k < strlen(b); k++)
		cout << next[k] << " ";
	cout << endl;
	cout << kmp(a, b);
	return 0;
}



//4.
 #include <iostream>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
using namespace std;


char* strrpc(char* dest, char* src, char* before, char* after) {
    size_t src_size = strlen(src);
    size_t before_str_size = strlen(before);
    size_t after_str_size = strlen(after);

    size_t dest_offset = 0;
    for (size_t src_offset = 0; src_offset < src_size; ) {
        if (!strncmp(src + src_offset, before, before_str_size)) {
            memcpy(dest + dest_offset, after, after_str_size);
            src_offset += before_str_size;
            dest_offset += after_str_size;
        }
        else {
            memmove(dest + dest_offset, src + src_offset, 1);
            dest_offset++;
            src_offset++;
        }
    }

    return dest;
}

int main()
{
    char a[1000], b[100], c[100], d[1000] = { NULL };
	cin.getline(a, 1000, '\n');
	cin.getline(b, 100, '\n');
	cin.getline(c, 100, '\n');
	strrpc(d,a, b, c);
    for (int i = 0; i < strlen(d); i++) {
            cout << d[i];
    }
		
	return 0;

}
//4.
#include <iostream>
#include <string>
using namespace std;
int main() {
	string s, b, a;

	cin >> s >> b >> a;
	int start=0,pos=0;
	while ((start = s.find(b, pos)) != -1) {
		s.replace(start, b.size(), a);
		pos = start + a.size();
	}
	cout << s;
	return 0;
}