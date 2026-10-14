#include <stdio.h>
#include <string.h>

#define MAX_VE 100

struct VeMayBay {
    char maVe[15];
    char tenHanhKhach[50];
    char hangVe[20];
    float canNangHanhLy;
    float cuocHanhLy;
};

int main() {
    struct VeMayBay danhSachVe[MAX_VE];
    int n, i, found = 0;
    char searchPNR[15];
    float tongCuoc = 0;
    int maxIndex = 0;

    printf("Nhap so luong ve may bay: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_VE) {
        printf("So luong ve khong hop le!\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin ve thu %d ---\n", i + 1);
        printf("Ma ve PNR: ");
        scanf("%s", danhSachVe[i].maVe);
        while (getchar() != '\n');

        printf("Ho ten hanh khach: ");
        fgets(danhSachVe[i].tenHanhKhach, sizeof(danhSachVe[i].tenHanhKhach), stdin);
        danhSachVe[i].tenHanhKhach[strcspn(danhSachVe[i].tenHanhKhach, "\n")] = 0;

        printf("Hang ve (Business/Deluxe/Eco): ");
        scanf("%s", danhSachVe[i].hangVe);

        do {
            printf("Khoi luong hanh ly ky gui (kg): ");
            scanf("%f", &danhSachVe[i].canNangHanhLy);
            if (danhSachVe[i].canNangHanhLy < 0) {
                printf("Can nang hanh ly khong duoc am! Vui long nhap lai.\n");
            }
        } while (danhSachVe[i].canNangHanhLy < 0);

        if (strcasecmp(danhSachVe[i].hangVe, "Business") == 0) {
            if (danhSachVe[i].canNangHanhLy <= 20) {
                danhSachVe[i].cuocHanhLy = 0;
            } else {
                danhSachVe[i].cuocHanhLy = (danhSachVe[i].canNangHanhLy - 20) * 50000;
            }
        } else {
            danhSachVe[i].cuocHanhLy = danhSachVe[i].canNangHanhLy * 50000;
        }
    }

    printf("\nNhap ma ve PNR can cap nhat hanh ly: ");
    scanf("%s", searchPNR);
    
    float newWeight = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(danhSachVe[i].maVe, searchPNR) == 0) {
            found = 1;
            do {
                printf("Nhap can nang hanh ly ky gui moi (kg): ");
                scanf("%f", &newWeight);
                if (newWeight < 0) {
                    printf("Can nang khong duoc am!\n");
                }
            } while (newWeight < 0);

            danhSachVe[i].canNangHanhLy = newWeight;
            if (strcasecmp(danhSachVe[i].hangVe, "Business") == 0) {
                if (danhSachVe[i].canNangHanhLy <= 20) {
                    danhSachVe[i].cuocHanhLy = 0;
                } else {
                    danhSachVe[i].cuocHanhLy = (danhSachVe[i].canNangHanhLy - 20) * 50000;
                }
            } else {
                danhSachVe[i].cuocHanhLy = danhSachVe[i].canNangHanhLy * 50000;
            }
            break;
        }
    }

    printf("\n================================== DANH SACH VE MAY BAY CHUYEN BAY ==================================\n");
    printf("%-4s %-12s %-25s %-12s %12s %15s\n", "STT", "MA VE", "HO TEN HANH KHACH", "HANG VE", "HANH LY (KG)", "CUOC PHI (VND)");
    printf("----------------------------------------------------------------------------------------------------\n");
    
    for (i = 0; i < n; i++) {
        printf("%-4d %-12s %-25s %-12s %12.1f %15.0f\n", 
            i + 1, danhSachVe[i].maVe, danhSachVe[i].tenHanhKhach, danhSachVe[i].hangVe, danhSachVe[i].canNangHanhLy, danhSachVe[i].cuocHanhLy);
        tongCuoc += danhSachVe[i].cuocHanhLy;
        if (danhSachVe[i].canNangHanhLy > danhSachVe[maxIndex].canNangHanhLy) {
            maxIndex = i;
        }
    }
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("Tong tien cuoc hanh ly toan chuyen: %.0f VND\n", tongCuoc);
    printf("Ve co hanh ly ky gui nang nhat: %s - %s (%.1f kg)\n", danhSachVe[maxIndex].maVe, danhSachVe[maxIndex].tenHanhKhach, danhSachVe[maxIndex].canNangHanhLy);

    printf("\n--- CAP NHAT THONG TIN HANH LY ---\n");
    if (found) {
        printf("Tim thay ma ve %s. Da cap nhat cuoc hanh ly moi: %.0f VND.\n", searchPNR, danhSachVe[i].cuocHanhLy);
    } else {
        printf("Khong tim thay ma ve PNR nay trong he thong!\n");
    }

    printf("\n================================ DANH SACH VE MAY BAY SAU CAP NHAT ================================\n");
    printf("%-4s %-12s %-25s %-12s %12s %15s\n", "STT", "MA VE", "HO TEN HANH KHACH", "HANG VE", "HANH LY (KG)", "CUOC PHI (VND)");
    printf("----------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-4d %-12s %-25s %-12s %12.1f %15.0f\n", 
            i + 1, danhSachVe[i].maVe, danhSachVe[i].tenHanhKhach, danhSachVe[i].hangVe, danhSachVe[i].canNangHanhLy, danhSachVe[i].cuocHanhLy);
    }
    printf("----------------------------------------------------------------------------------------------------\n");

    return 0;
}
