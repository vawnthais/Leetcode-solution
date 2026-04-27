import pandas as pd

import pandas as pd

def average_selling_price(prices: pd.DataFrame, units_sold: pd.DataFrame) -> pd.DataFrame:
    # 1. Kết nối 2 bảng (Left Join để giữ mọi sản phẩm trong danh mục giá)
    df = pd.merge(prices, units_sold, on='product_id', how='left')
    
    # 2. Tạo 2 cột mới và đặt tất cả bằng 0
    df['valid_units'] = 0
    df['revenue'] = 0.0
    
    # 3. Dùng .loc để chỉ cập nhật những hàng đúng ngày tháng
    # Mask này kiểm tra: Ngày mua nằm trong khoảng Start và End
    mask = (df['purchase_date'] >= df['start_date']) & (df['purchase_date'] <= df['end_date'])
    
    # Chỉ những dòng thỏa mãn mask mới được lấy giá trị thật từ bảng
    df.loc[mask, 'valid_units'] = df['units']
    df.loc[mask, 'revenue'] = df['price'] * df['units']
    
    # 4. Gom nhóm theo product_id và tính tổng
    result = df.groupby('product_id').agg(
        total_rev=('revenue', 'sum'),
        total_units=('valid_units', 'sum')
    ).reset_index()
    
    # 5. Tính giá trung bình bằng công thức:
    # Average Price = Tổng doanh thu / Tổng số lượng
    # fillna(0) để xử lý trường hợp 0 / 0
    result['average_price'] = (result['total_rev'] / result['total_units']).fillna(0).round(2)
    
    return result[['product_id', 'average_price']]