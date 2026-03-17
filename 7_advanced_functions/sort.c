int scores[] = {543, 323, 32, 554};

int compare_scores_desc(const void* score_a, const void* score_b){
	int a = *(int*)score_a;
	int b = *(int*)score_b;
	return b - a;
}

typedef struct{
	int width;
	int height;
} rectangle;


int compare_areas(const void* a, const void *b)
{
	
}
