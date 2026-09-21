#include<stdio.h>
#include <windows.h>
#include <locale.h>

void print_metric_menu() {
    printf("\n=== Metric Units ===\n");
    printf("1. Picometers (pm)(皮米)\n");
    printf("2. Nanometers (nm)(纳米)\n");
    printf("3. Micrometers (µm)(微米)\n");
    printf("4. Millimeters (mm)(毫米)\n");
    printf("5. Centimeters (cm)(厘米)\n");
    printf("6. Decimeters (dm)(分米)\n");
    printf("7. Meters (m)(米)\n");
    printf("8. Kilometers (km)(千米)\n");
    printf("9. Light Years (ly)(光年)\n");
    printf("10. Astronomical Units (AU)(天文单位)\n");
    printf("Please choose a unit to convert from: ");
}

void print_imperial_menu() {
    printf("\n=== Imperial Units ===\n");
    printf("1. Inches (in)(英寸)\n");
    printf("2. Feet (ft)(英尺)\n");
    printf("3. Yards (yd)(码)\n");
    printf("4. Miles (mi)(英里)\n");
    printf("5. Nautical Miles (NM)(海里)\n");
    printf("Please choose a unit to convert from: ");
}

void print_chinese_menu() {
    printf("\n=== Chinese Units ===\n");
    printf("1. Li (里)\n");
    printf("2. Zhang (丈)\n");
    printf("3. Chi (尺)\n");
    printf("4. Cun (寸)\n");
    printf("5. Fen (分)\n");
    printf("6. Li (厘)\n");
    printf("7. Hao (毫)\n");
    printf("Please choose a unit to convert from: ");
}
