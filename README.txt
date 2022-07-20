Xin Chào
đây là ứng dụng hiển thị thông tin hỗ trợ lái xe.
Đoạn code này được viết trên visual studio.
Khi chạy đoạn code lên
	. Đầu tiên bạn cần nhập số xe mà bạn muốn tạo, có thể thay đổi số lượng xe tùy ý.
	. tiếp theo bạn cần đăng nhập mật khẩu vào thay cho chìa khóa xe.
		. nếu xe chưa được cài đặt mật khẩu thì bạn hãy cài lại.
		. nhập mật khẩu bạn vừa cài.
		. sau khi đăng nhập thành công, bạn có thể thiết lập lại mật khẩu mới nếu muốn.
	. Tiếp theo bạn sẽ chọn các mốc tốc độ mà bạn muốn hệ thống cảnh báo.
		. nếu xe chưa được cài đặt các mức cảnh báo thì bạn hãy cài lại,có thể thay đổi tùy ý, nhưng nếu bạn nhập 3 mức vận tốc trùng với 3 mức vận tốc cũ thì sẽ chương trình sẽ không lưu. 
	. Tiếp theo bạn sẽ được chọn các tay số giống hệt như trên xe ô tô.
		. Số P: Tức là đưa xe về chế độ đỗ xe. Ở chế độ này hộp số sẽ ở chế độ P và bánh xe sẽ bị bó cứng.
		. Số N: Cũng là đưa xe về chế độ đỗ xe. Chỉ khác số P là bánh xe không bị bó cứng, nếu không sử dụng phanh thì ô tô sẽ bị trôi.
		. Số R: Đơn giản là để số lùi, đùng để điều khiển xe lùi về phía sau.
		. Số D: Đơn giản là số tiến, dùng để điều khiển xe tiến về phía trước.
	. Tiếp theo khi vào số R hoặc D trên màn hình sẽ cho bạn chọn các chế độ: tăng tốc, giảm tốc, phanh, trở về menu.
		. Khi chọn R hoặc D mặc định tốc độ sẽ tăng lên 7km
		. Khi bạn chọn tăng tốc, tốc độ của xe sẽ tăng lên 5km và giảm tốc thì ngược lại.
		. Khi bạn chọn phanh, xe sẽ dừng lại, tốc độ sẽ về 0km.
		. Khi bạn chọn trở về menu, thì bắc buộc bạn phải dừng xe mới chọn được, tức là tốc độ xe phải về 0km mới có thể chọn sang số khác.
		. Ở Tay số R khi tốc độ xe vượt quá 20km và vượt quá 60km đối với tay số D, màn hình sẽ hiển thị thông báo: *** CHU Y: TOC DO NGUY HIEM, BAN NEN GIAM TOC DO LAI NHE.
	. Tiếp theo nếu bạn muốn tắt máy, hãy chọn POWER OFF.
