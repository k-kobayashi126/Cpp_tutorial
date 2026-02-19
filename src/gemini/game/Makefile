CXX      = g++
CXXFLAGS = -Wall -Wextra -Iinclude
SRC_DIR  = src
OBJ_DIR  = build
# 実行ファイル名を build/main に設定
TARGET   = $(OBJ_DIR)/main

# ソースとオブジェクトのリスト
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# デフォルトターゲット
all: $(TARGET)

# 実行ファイルのリンク
$(TARGET): $(OBJS)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 各ソースファイルのコンパイル
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# クリーンアップ
clean:
	rm -rf $(OBJ_DIR)

# 実行
run: all
	./$(TARGET)

.PHONY: all clean run