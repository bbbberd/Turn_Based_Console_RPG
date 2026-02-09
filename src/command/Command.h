#pragma once // pragma once = pastikan file ini hanya di-include SATU KALI
// mencegah error definisi ganda

class Command {// Base class Command
public:
    virtual ~Command() = default;// virtual destructor
    // penting supaya delete lewat pointer base class AMAN

    virtual void Execute() = 0;// fungsi virtual murni (pure virtual)
    // = 0 artinya:
    // - class ini TIDAK BISA dibuat object
    // - class turunan WAJIB override Execute()
};
