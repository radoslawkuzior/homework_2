#ifndef CLASS_H
#define CLASS_H

#endif // CLASS_H


#include <iostream>

class Time {
private:
    int seconds;
public:
    Time(int sec = 0) {
        seconds = sec;
    }

    Time(int h, int m, int s) {
        seconds = (h * 3600) + (m * 60) + s;
    }

    Time operator+(const Time &t) const {
        return Time(seconds + t.seconds);
    }

    Time operator-(const Time &t) const {
        return Time(seconds - t.seconds);
    }

    Time operator*(int num) const {
        return Time(seconds * num);
    }

    operator int() const {
        return seconds;
    }

    friend std::ostream &operator<<(std::ostream &out, const Time &t) {
        int h = t.seconds / 3600;
        int m = (t.seconds % 3600) / 60;
        int s = t.seconds % 60;

        if (h < 10) out << "0";
        out << h << "m:";

        if (m < 10) out << "0";
        out << m << "m:";

        if (s < 10) out << "0";
        out << s << "s";

        return out;
    }

    friend std::istream &operator>>(std::istream &in, Time &t) {
        int h, m, s;
        char c1, c2;
        in >> h >> c1 >> m >> c2 >> s;

        if (c1 == 'h' && c2 == 'm') {
            t = Time(h, m, s);
        }
        return in;
    }
};

///

#ifndef ITEM_H
#define ITEM_H

#endif // ITEM_H

#include <iostream>
#include <vector>
#include <string>

class Item {
private:
    std::string name;
    double unit_price;
    char vat_type;
    int quantity;

public:
    Item(std::string name, double price, char vat, int qty)
        : name(name), unit_price(price), vat_type(vat), quantity(qty) {}

    double net_price() const {
        return unit_price * quantity;
    }

    double vat_rate() const {
        switch (vat_type) {
        case 'A': return 0.23;
        case 'B': return 0.08;
        case 'C': return 0.0;
        default: return 0.0;
        }
    }

    double total_price() const {
        return net_price() * (1 + vat_rate());
    }

    friend std::ostream &operator<<(std::ostream &out, const Item &item) {
        out << item.name << " | "
            << item.unit_price << " " << item.vat_type << " | "
            << item.quantity << " | " << item.net_price() << " | "
            << item.total_price();
        return out;
    }
};

class Invoice {
private:
    std::string seller_nip;
    std::string buyer_nip;
    std::vector<Item> items;

public:
    Invoice(std::string seller, std::string buyer) : seller_nip(seller), buyer_nip(buyer) {}

    void add_item(const Item &item) {
        items.push_back(item);
    }

    friend std::ostream &operator<<(std::ostream &out, const Invoice &invoice) {
        out << "------------------VAT invoice------------------\n";
        out << "===============================================\n";
        out << "Seller: " << invoice.seller_nip << "      Buyer: " << invoice.buyer_nip << "\n\n";
        out << "                  c.j. VAT   il.    net   total\n";
        double total_net = 0, total_gross = 0;
        int index = 1;
        for (const auto &item : invoice.items) {
            out << index++ << ". " << item << "\n";
            total_net += item.net_price();
            total_gross += item.total_price();
        }
        out << "\n------------------------------------ TOTAL ----\n";
        out << "                                  " << total_net << " | " << total_gross << "\n";
        return out;
    }
};

