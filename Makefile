# Direktori untuk source code
ADT_DIR = ADT
BALASAN_DIR = Balasan
DRAF_DIR = DrafKicauan
GENERAL_DIR = General
INISIALISASI_DIR = Inisialisasi
KICAUAN_DIR = Kicauan
PENGGUNA_DIR = Pengguna
PERMINTAAN_DIR = PermintaanTeman
TEMAN_DIR = Teman
UTAS_DIR = Utas
FOTO_PROFIL_DIR = FotoProfil

# Direktori untuk objek files
BUILD_DIR = build

# Compiler dan flags
CC = gcc
CFLAGS = -Wall -std=c11 -MMD

# Source files
MAIN_SOURCES = main.c
ADT_SOURCES = $(ADT_DIR)/*.c
BALASAN_SOURCES = $(BALASAN_DIR)/balasan.c $(BALASAN_DIR)/commandBalasan.c $(BALASAN_DIR)/tabBalasan.c
DRAF_SOURCES = $(DRAF_DIR)/draf.c $(DRAF_DIR)/commandDraf.c
GENERAL_SOURCES = $(GENERAL_DIR)/*.c
INISIALISASI_SOURCES = $(INISIALISASI_DIR)/*.c
KICAUAN_SOURCES = $(KICAUAN_DIR)/kicauan.c $(KICAUAN_DIR)/commandKicauan.c $(KICAUAN_DIR)/tabKicauan.c
PENGGUNA_SOURCES = $(PENGGUNA_DIR)/pengguna.c $(PENGGUNA_DIR)/commandPengguna.c $(PENGGUNA_DIR)/tabPengguna.c
PERMINTAAN_SOURCES = $(PERMINTAAN_DIR)/permintaanTeman.c $(PERMINTAAN_DIR)/commandPermintaanTeman.c 
TEMAN_SOURCES = $(TEMAN_DIR)/teman.c $(TEMAN_DIR)/commandTeman.c 
UTAS_SOURCES = $(UTAS_DIR)/utas.c $(UTAS_DIR)/commandUtas.c $(UTAS_DIR)/tabUtas.c
FOTO_PROFIL_SOURCES = $(FOTO_PROFIL_SOURCES)/utas.c $(FOTO_PROFIL_SOURCES)/commandUtas.c $(FOTO_PROFIL_SOURCES)/tabUtas.c

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

$(BUILD_DIR)/%.o: $(ADT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(BALASAN_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(DRAF_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(GENERAL_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(INISIALISASI_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(KICAUAN_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(PERMINTAAN_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEMAN_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(UTAS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(PENGGUNA_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Aturan untuk membuat executable
main: $(BUILD_DIR) $(MAIN_OBJ) $(ADT_OBJ) $(GENERAL_OBJ) $(BALASAN_OBJ) $(KICAUAN_OBJ) $(DRAF_OBJ) $(INISIALISASI_OBJ) $(PERMINTAAN_OBJ) $(TEMAN_OBJ) $(PENGGUNA_OBJ) $(UTAS_OBJ)
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

-include $(BUILD_DIR)/*.d
