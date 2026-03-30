// Format: {Merah, Kuning, Hijau}
const int lampu[4][3] = {
  {13, 12, 11}, // Utara
  {10, 9, 8},   // Timur
  {7, 6, 5},    // Selatan
  {4, 3, 2}     // Barat
};

void setup() {
  // Set semua pin OUTPUT 
  for (int i = 0; i < 4; i++) {
    pinMode(lampu[i][0], OUTPUT);
    pinMode(lampu[i][1], OUTPUT);
    pinMode(lampu[i][2], OUTPUT);
  }

  semuaMerah();
}

void loop() {
  // Urutan searah jarum jam
  aktifkanSimpang(0); // Utara
  aktifkanSimpang(1); // Timur
  aktifkanSimpang(2); // Selatan
  aktifkanSimpang(3); // Barat
}

// Semua lampu merah
void semuaMerah() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(lampu[i][0], HIGH); // Merah
    digitalWrite(lampu[i][1], LOW);  // Kuning
    digitalWrite(lampu[i][2], LOW);  // Hijau
  }
}

// Kontrol satu simpang
void aktifkanSimpang(int i) {
  digitalWrite(lampu[i][0], LOW); // Matikan merah

  // Hijau 5 detik
  digitalWrite(lampu[i][2], HIGH);
  delay(5000);
  digitalWrite(lampu[i][2], LOW);

  // Kuning kedip 3x
  for (int j = 0; j < 3; j++) {
    digitalWrite(lampu[i][1], HIGH);
    delay(250);
    digitalWrite(lampu[i][1], LOW);
    delay(250);
  }

  // Kuning 2 detik
  digitalWrite(lampu[i][1], HIGH);
  delay(2000);
  digitalWrite(lampu[i][1], LOW);

  // Kembali merah
  digitalWrite(lampu[i][0], HIGH);
}
