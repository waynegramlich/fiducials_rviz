
#ifdef __cplusplus 
extern "C" {
#endif

void* initRviz(int argc, char **argv, char *nodeName);

void sendMarker(void* rd, char *frame, double x, double y, double z);

#ifdef __cplusplus
}
#endif
