
#ifdef __cplusplus 
extern "C" {
#endif

extern void *initRviz(int argc, char **argv, char *nodeName);

extern void sendMarker(void* rd, char *frame, int id,
  double x, double y, double z,
  double twist, double dx, double dy, double dz);

void sendArrow(void* rd, char *frame, int id, double x, double y, double z,
  double twist, double dx, double dy, double dz, double bearing);

extern int isOK();

#ifdef __cplusplus
}
#endif
