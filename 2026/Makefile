CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -g
TARGET = program
OBJDIR = .objs

SRCS = checkfile.cpp utils/utils.cpp scenes/scenes.cpp tampfile.cpp tampfileutils.cpp
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CXX) $(OBJS) -o $(TARGET)
$(OBJDIR)/%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS) $(TARGET)
    rm -rf $(OBJDIR)

re: clean
    @make all

.PHONY: all clean