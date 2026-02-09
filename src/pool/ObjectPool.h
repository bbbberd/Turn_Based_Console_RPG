#pragma once
#include <vector>

template <typename T>// ===== TEMPLATE =====
// Artinya class ini BELUM punya tipe pasti.
// Nanti bisa jadi ObjectPool<Enemy>, ObjectPool<Bullet>, dll
class ObjectPool {
private:
    std::vector<T*> pool;// Vector berisi POINTER ke object T
    // disimpan di heap
    // Contoh nyata:
    // Jika T = Enemy
    // maka ini menjadi:
    // std::vector<Enemy*> pool;

public:
    ~ObjectPool() {// Destructor -> dipanggil saat ObjectPool dihancurkan
        for (auto* obj : pool)
            delete obj;// Loop semua object yang tersimpan di pool
        // delete artinya membebaskan memory di heap
        // Penting supaya tidak memory leak
    }

    T* GetObject() {// Fungsi untuk "meminjam" object dari pool
        if (pool.empty())
            return new T();// Jika pool kosong:
        // Buat object baru di heap
        // new T() -> T bisa Enemy, Bullet, dll

        T* obj = pool.back();// Ambil object terakhir dari vector

        pool.pop_back();// Hapus dari vector (karena sekarang sedang dipakai)
        return obj;// Kembalikan pointer object ke pemanggil
    }

    void ReturnObject(T* obj) {// Fungsi untuk mengembalikan object ke pool
        
        pool.push_back(obj);// Simpan kembali object supaya bisa dipakai lagi
        // Tidak di-delete -> supaya tidak buat object baru lagi
    }
};
