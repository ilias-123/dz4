#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){

	printf("Count: ");
	int n;
	scanf("%d",&n);

	int graph[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			graph[i][j] = 0;
		}
	}

	printf("Fill the names of elements\n");
	char *name[n];

	for (int i = 0; i < n; i++){
		printf("# ");
		char *sname = (char*) malloc(20 * sizeof(char));
		scanf("%s", sname);
		name[i] = sname;
	}

	printf("Connections\n");

	for (int i = 0; i < n; i++){
		printf("#%d: %s\n", i + 1, name[i]);
		_Bool flag = 1;

		while (flag){
			char* cmp_sting = (char*) malloc(20 * sizeof(char));
			scanf("%s", cmp_sting);

			for (int j = 0; j < n; j++){
				if (strcmp(name[j], cmp_sting) == 0){
					graph[i][j] = 1;
					graph[j][i] = 1;
				}
			}

			if (strcmp(cmp_sting, ";") == 0){
				flag = 0;
			}

			free(cmp_sting);
		}
	}

	for (int i = 0; i < n; i++){
		printf("#%4s: ", name[i]);
		for (int j = 0; j < n; j++){
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}



	char* arr = (char*) calloc(500, sizeof(char));

	strcat(arr, "graph G {");
	for (int i = 0; i < n; i++){
		strcat(arr, name[i]);
		strcat(arr, ";");
	}
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			if (graph[i][j] > 0){
				strcat(arr, name[i]);
				strcat(arr, "--");
				strcat(arr, name[j]);
				strcat(arr, ";");
			}
		}
	}
	strcat(arr, "}");

	FILE* f = fopen("graph.dot", "w");
	fprintf(f, "%s\n", arr);
	fclose(f);

	free(arr);

	int max = 0;
	int max_index;

	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = 0; j < n; j++){
			sum += graph[i][j];
		}

		if (sum >= max){
			max = sum;
		}
	}

    int k = 0;
    int arrn[n];
    for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = 0; j < n; j++){
			sum += graph[i][j];
		}

		if (sum == max){
            arrn[k] = i;
            k++;
		}
	}

	for (int h = 0; h < k; h++){
        int i = arrn[h];
        for (int j = 0; j < n; j++){
		    if ((graph[i][j] != 0) && (graph[j][i] != 0)){
                printf("%s-%s\n", name[i], name[j]);
                graph[i][j] = 0;
		    }
	    }
    }
	

	return 0;
}
