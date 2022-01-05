# Chương Trình Quản Lý Tài Ngân Hàng

#Chương trình quản lý ngân hàng gồm các chức năng như quản lý hệ thống  nhân viên, hệ thống khách hàng, các dịch vụ đi kèm như sử dụng thẻ tín dụng ATM, dịch vụ Ví điện tử.

Các danh sách khách hàng, danh sách nhân viên, danh sách lịch sử giao dịch, danh sách ví điện tử sẽ được lưu trữ dựa trên cấu trúc dữ liệu danh sách liên kết. Dữ liệu sẽ được đọc từ các file KHACHHANG.txt, NHANVIEN.txt, LichSuGiaoDich.txt, ViDienTu.txt.

• File KHACHHANG.txt: dòng đầu tiên chứa số lượng khách hàng, các dòng tiếp theo chứa thông tin các khách hàng, mỗi khách hàng sẽ có các thông tin chứa trên từng dòng của file 
như: IdKhachHang, họ tên, tuổi, địa chỉ, số điện thoại, số tài khoản ATM, mật khẩu ATM, số dư của khách hàng. Các khách hàng được xếp nối tiếp nhau với thứ tự IdKhachHang (KHx) 
tăng dần.

• File NHANVIEN.txt: dòng đầu tiên chứa số lượng nhân viên, các dòng tiếp theo chứa thông tin các nhân viên, mỗi nhân viên sẽ có các thông tin chứa trên từng dòng của file như: 
IdNhanVien, họ tên, tuổi, địa chỉ, số điện thoại, mã tài khoản, mật khẩu. Các nhân viên được xếp nối tiếp nhau với thứ tự IdNhanVien (NVx) tăng dần.

• File LichSuGiaoDich.txt: dòng đầu tiên chứa số lượng các giao dịch, các dòng tiếp theo chứa các lịch sử giao dịch với cac thông tin như: mã giao dịch, nội dung của giao dịch, số tài khoản thực hiện giao dịch.

• File ViDienTu.txt: các dòng chứa lần lượt mã tài khoản ví, mật khẩu, số lượng thẻ ATM liên kết với ví, các thẻ ATM liên kết với ví, số tiền trong ví điện tử
