TARGET = bt_a2dp.prx
OBJS = src/bt_a2dp_main.c

CFLAGS = -O3 -Wall -fPIC -shared -DA2DP -DAVDTP -DSBC
LDFLAGS =

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
