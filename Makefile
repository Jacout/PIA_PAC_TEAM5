CXX := g++
CXXFLAGS := -std=c++17 -g -Wall -Wextra -I./src
LDFLAGS := -lpcap -lssl -lcrypto
SRCDIR := src
BINDIR := bin
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(SRCDIR)/%.o,$(SOURCES))
TARGET_DEBUG := $(BINDIR)/pia_team5_debug
TARGET_STRIPPED := $(BINDIR)/pia_team5_stripped

.PHONY: all debug stripped clean

all: debug stripped

debug: $(BINDIR) $(TARGET_DEBUG)

$(BINDIR):
	mkdir -p $(BINDIR)

$(TARGET_DEBUG): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

stripped: $(TARGET_STRIPPED)

$(TARGET_STRIPPED): $(TARGET_DEBUG)
	cp $(TARGET_DEBUG) $(TARGET_STRIPPED)
	strip --strip-all $(TARGET_STRIPPED) || true

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(SRCDIR)/*.o $(BINDIR)
