# 🐦 Flappy Bird - C++ Logic Engine

Dự án mô phỏng trò chơi Flappy Bird nguyên bản với sự kết hợp giữa **C++ (Hệ thống xử lý logic)** và **Web Interface (Hiển thị & Âm thanh)**.

## 🏗️ Kiến trúc dự án
Dự án được tách biệt rõ ràng thành hai phần:
1. **Core Engine (`main.cpp`)**: Đóng vai trò là "Bộ não". Quản lý các biến số vật lý như trọng lực, vận tốc rơi, logic va chạm và hệ thống tính điểm (đạt 100 điểm để thắng).
2. **Display Interface (`index.html`)**: Đóng vai trò là "Màn hình hiển thị". Biên dịch các thông số từ logic C++ sang hình ảnh và phát âm thanh từ tài nguyên thực tế.



## 📁 Tài nguyên (Assets)
Sử dụng bộ tài nguyên gốc bao gồm:
- **Images**: Hình ảnh chim (3 trạng thái vỗ cánh), ống nước, nền trời và mặt đất (`assets/images/`).
- **Audio**: Hiệu ứng âm thanh khi nhảy (wing), ăn điểm (point), va chạm (hit) và thua cuộc (die) (`assets/audio/`).

## 🚀 Cách chạy dự án
1. **Xem mã nguồn**: Mở file `main.cpp` để xem logic xử lý chính của game.
2. **Chơi thử**: Truy cập trực tiếp qua GitHub Pages (Link của bạn ở đây).
3. **Cài đặt cục bộ**:
   - Giải nén thư mục `assets` vào cùng thư mục với `index.html`.
   - Mở `index.html` bằng trình duyệt bất kỳ.

## 🎮 Điều khiển
- **Phím Space / Click chuột**: Giúp chim bay lên.
- **Mục tiêu**: Vượt qua các ống nước để đạt 100 điểm.

## 🛠️ Công nghệ sử dụng
- **C++**: Logic Core & Physics.
- **HTML5 Canvas**: Rendering Graphics.
- **JavaScript**: Bridge & Audio Management.
