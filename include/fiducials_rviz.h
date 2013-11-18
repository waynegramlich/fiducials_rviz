
#ifdef __cplusplus 
extern "C" {
#endif

void* initRviz(int argc, char **argv, char *nodeName);

void sendMarker(void* rd, char *frame, int id, double x, double y, double z);

int isOK();

#ifdef __cplusplus
}
#endif
