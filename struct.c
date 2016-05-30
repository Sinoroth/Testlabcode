typedef struct {
  int x, y;
} Point;

Point point_new(int x, int y)
{
  Point a;
  a.x = x;
  a.y = y;
  return a;
}