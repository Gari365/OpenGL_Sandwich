# 🎓 Identitas Mahasiswa 
- **Nama:** Garrison Tanvanno  
- **NIM:** 03082230011  
- **Kelas:** 23TI1  

---

# 🎯 1. Tujuan 
- Mampu menggunakan library pemrograman OpenGL untuk membuat, menampilkan, serta memanipulasi model 3D.  
- Memahami konsep dasar pemodelan bangun ruang 3D menggunakan vertex, indeks, dan atribut warna.  
- Menerapkan transformasi 3D (rotasi, translasi, dan scaling) pada objek dengan memanfaatkan fitur OpenGL.  
- Memahami teknik rendering sederhana: proyeksi, perspektif, shader, pencahayaan (lighting), pewarnaan, dan pencitraan (rasterization).  

---

# 📦 2. Deskripsi Tugas 
- **Bangun ruang yang dimodelkan**  
  Sandwich/roti lapis yang terdiri dari roti, ham, selada, dan acar.  

- **Penjelasan singkat**  
  Objek sandwich dibuat dengan menyusun beberapa balok tipis untuk roti dan isiannya, yaitu:  
  - Roti atas & bawah (balok tipis warna krem).  
  - Selada (balok tipis hijau, sedikit diputar).  
  - Ham (balok tipis warna merah muda).  
  - Acar/pickle (kubus kecil pipih hijau muda).  
  - Model ditampilkan dalam ruang 3D menggunakan OpenGL dengan transformasi, pencahayaan, dan pewarnaan.  

---

# 🛠️ 3. Implementasi Program 

### a. Pemodelan Bangun Ruang 
- Menggunakan fungsi `addCube()` untuk membuat vertex, normal, dan indeks balok.  
- Parameter posisi, ukuran, dan warna diberikan untuk membedakan tiap lapisan sandwich.  

### b. Transformasi 3D  
- **Rotasi:** Sandwich diputar kontinu pada sumbu Y agar terlihat dari berbagai sudut.  
- **Translasi:** Setiap lapisan diposisikan berbeda pada sumbu Y, acar diposisikan bervariasi di sumbu X dan Z.  
- **Scaling:** Ukuran sandwich dapat diperbesar/diperkecil relatif terhadap pusat objek.  

### c. Rendering  
- **Lighting:** Pencahayaan sederhana dengan ambient, diffuse, dan specular light untuk efek terang-gelap.  
- **Pewarnaan:** Warna solid (roti krem, selada hijau, ham merah muda, acar hijau muda).  

### d. Kamera / Projection  
- **Pergerakan kamera:** Tombol W, S, A, D untuk maju, mundur, kiri, kanan.  
- **Rotasi kamera:** Gerakan mouse untuk memutar arah pandangan.  
- **Proyeksi:** Perspektif 3D (perspective projection) agar tampilan lebih realistis.  

---

# 📸 4. Hasil dan Dokumentasi 
- **Tampak samping**  
  ![Tampak Samping](https://github.com/user-attachments/assets/765261e6-2a4e-4b9a-b8a8-4cbf03323865)  

- **Tampak depan**  
  ![Tampak Depan](https://github.com/user-attachments/assets/6c3d3dd1-65dc-450a-9ae6-3b844b216ef3)  

- **Tampak atas**  
  ![Tampak Atas](https://github.com/user-attachments/assets/a81ca5ab-81af-4ef7-9e07-c78e507b110b)  

- **Skala & Rotasi**  
  ![Skala](https://github.com/user-attachments/assets/d1f60c17-8833-4759-9e5e-b6f75c89055d)  
  ![Rotasi](https://github.com/user-attachments/assets/bc8cabf9-0bc8-4abe-b98a-32aa1974f6eb)  

---

# 💻 5. Kode Program 
**Struktur folder proyek:**  
- `main.cpp` → File utama (inisialisasi OpenGL, shader, model, render loop).  
- `default.vert`, `default.frag` → Shader utama sandwich.  
- `light.vert`, `light.frag` → Shader sumber cahaya.  
- `Camera.h`, `Camera.cpp` → Kelas kamera 3D (posisi, arah, kontrol input).  
- `shaderClass.h`, `shaderClass.cpp` → Kelas pemuat & compiler shader.  
- `Texture.h`, `Texture.cpp` → Kelas loader tekstur PNG (opsional).  
- `stb.cpp` → Loader gambar dengan stb_image.  
- `VAO.h`, `VAO.cpp` → Pengaturan Vertex Array Object.  
- `VBO.h`, `VBO.cpp` → Pengiriman data vertex ke GPU.  
- `EBO.h`, `EBO.cpp` → Penggunaan indeks mesh dengan `glDrawElements`.  
- `glad.c` → Loader fungsi OpenGL.  
- `OpenGL_Sandwich.sln / .vcxproj / .filters / .user` → Konfigurasi Visual Studio.  
- `Libraries/` → Dependensi (GLFW, glm, stb, dll).  
- `x64/` → Output binary build.  

---

# ▶️ 6. Cara Menjalankan Program 
1. **Build Project**  
   - Buka `OpenGL_Sandwich.sln` di Visual Studio.  
   - Pastikan library (GLFW, GLAD, glm, stb) tersedia.  
   - Tekan **Build**.  

2. **Jalankan Program**  
   - Tekan **Run** atau **F5**.  

3. **Kontrol Kamera**  
   - W/S/A/D → Gerakan maju/mundur/kiri/kanan.  
   - Mouse → Rotasi kamera.  

4. **Kontrol Objek**  
   - ← / → → Rotasi sandwich.  
   - ↑ / ↓ → Scaling sandwich.  

5. **Pengamatan Scene**  
   - Kombinasikan kontrol kamera dengan rotasi & scaling untuk mengeksplorasi sandwich dari berbagai sudut.  

---

# 📝 7. Kesimpulan 
<p>Dalam proyek ini, saya mempelajari bagaimana memodelkan objek 3D sederhana menggunakan OpenGL, khususnya menggunakan kubus untuk membentuk objek yang lebih kompleks seperti sandwich. Proses ini mengajarkan bagaimana menentukan posisi, ukuran, dan orientasi setiap bagian agar membentuk model yang utuh tanpa celah.</p>  
<p>Selain itu, saya memahami penerapan transformasi 3D seperti rotasi, translasi, dan scaling untuk membuat model dapat berinteraksi dengan input pengguna, serta pentingnya penerapan proyeksi perspektif agar tampilan lebih realistis.</p>  
<p>Begitu juga, penggunaan pencahayaan sederhana dan pewarnaan solid memberikan pengalaman dasar dalam rendering, dan pengaturan kamera interaktif memperkuat pemahaman terhadap navigasi di ruang 3D, yang menjadi fondasi penting untuk pengembangan aplikasi grafis 3D lebih lanjut.</p>
