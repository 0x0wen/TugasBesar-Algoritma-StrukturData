# Direktori untuk source code
ADT_DIR = ADT
BALASAN_DIR = Balasan
DRAF_DIR = DrafKicauan
GENERAL_DIR = General
INISIALISASI_DIR = Inisialisasi
KICAUAN_DIR = Kicauan
PENGGUNA_DIR = Pengguna
PERMINTAAN_DIR = Permintaan-pertemanan
TEMAN_DIR = Teman
UTAS_DIR = Utas

# Direktori untuk objek files
BUILD_DIR = build

# Compiler dan flags
CC = gcc
CFLAGS = -Wall -std=c11

# Source files
MAIN_SOURCES = main.c
ADT_SOURCES = $(wildcard $(ADT_DIR)/*.c)
BALASAN_SOURCES = $(wildcard $(BALASAN_DIR)/*.c)
DRAF_SOURCES = $(wildcard $(DRAF_DIR)/*.c)
GENERAL_SOURCES = $(wildcard $(GENERAL_DIR)/*.c)
INISIALISASI_SOURCES = $(wildcard $(INISIALISASI_DIR)/*.c)
KICAUAN_SOURCES = $(wildcard $(KICAUAN_DIR)/*.c)
PENGGUNA_SOURCES = $(wildcard $(PENGGUNA_DIR)/*.c)
PERMINTAAN_SOURCES = $(wildcard $(PERMINTAAN_DIR)/*.c)
TEMAN_SOURCES = $(wildcard $(TEMAN_DIR)/*.c)
UTAS_SOURCES = $(wildcard $(UTAS_DIR)/*.c)

# Objek files
MAIN_OBJ = $(BUILD_DIR)/main.o
ADT_OBJ = $(patsubst $(ADT_DIR)/%.c,$(BUILD_DIR)/%.o, $(ADT_SOURCES))
BALASAN_OBJ = $(patsubst $(BALASAN_DIR)/%.c,$(BUILD_DIR)/%.o, $(BALASAN_SOURCES))
DRAF_OBJ = $(patsubst $(DRAF_DIR)/%.c,$(BUILD_DIR)/%.o, $(DRAF_SOURCES))
GENERAL_OBJ = $(patsubst $(GENERAL_DIR)/%.c,$(BUILD_DIR)/%.o, $(GENERAL_SOURCES))
INISIALISASI_OBJ = $(patsubst $(INISIALISASI_DIR)/%.c,$(BUILD_DIR)/%.o, $(INISIALISASI_SOURCES))
KICAUAN_OBJ = $(patsubst $(KICAUAN_DIR)/%.c,$(BUILD_DIR)/%.o, $(KICAUAN_SOURCES))
PENGGUNA_OBJ = $(patsubst $(PENGGUNA_DIR)/%.c,$(BUILD_DIR)/%.o, $(PENGGUNA_SOURCES))
PERMINTAAN_OBJ = $(patsubst $(PERMINTAAN_DIR)/%.c,$(BUILD_DIR)/%.o, $(PERMINTAAN_SOURCES))
TEMAN_OBJ = $(patsubst $(TEMAN_DIR)/%.c,$(BUILD_DIR)/%.o, $(TEMAN_SOURCES))
UTAS_OBJ = $(patsubst $(UTAS_DIR)/%.c,$(BUILD_DIR)/%.o, $(UTAS_SOURCES))

# Target utama
all: $(BUILD_DIR) main
	./main

# Aturan untuk membuat objek files dari source files
$(BUILD_DIR)/main.o: $(MAIN_SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@

# Aturan untuk membuat executable
main: $(BUILD_DIR) $(MAIN_OBJ) $(ADT_OBJ) $(BALASAN_OBJ) $(DRAF_OBJ) $(GENERAL_OBJ) $(INISIALISASI_OBJ) $(KICAUAN_OBJ) $(PENGGUNA_OBJ) $(PERMINTAAN_OBJ) $(TEMAN_OBJ) $(UTAS_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Target untuk menjalankan program
run: main
	./main

# Target untuk membersihkan objek files dan executable
clean:
	rm -rf $(BUILD_DIR)/*.o main

# Membuat direktori build jika belum ada
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
