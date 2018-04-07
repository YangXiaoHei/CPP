//
//  main.cpp
//  Learning
//
//  Created by YangHan on 2018/4/6.
//  Copyright © 2018年 YangHan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace YH {
    class StrBlob {
    public:
        typedef vector<string>::size_type size_type;
        StrBlob();
        StrBlob(initializer_list<string> il);
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        
        void push_back(const string &t) { data->push_back(t); }
        void pop_back();
        
        string& front();
        string& back();
    private:
        shared_ptr<vector<string>> data;
        void check(size_type i, const string &msg) const;
    };
    StrBlob::StrBlob() :
            data(make_shared<vector<string>>()) {}
    StrBlob::StrBlob(initializer_list<string> il) :
            data(make_shared<vector<string>>(il)) {}
    void StrBlob::check(size_type i, const string &msg) const {
        if (i >= data->size()) {
            throw out_of_range(msg);
        }
    }
    string& StrBlob::front() {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    string& StrBlob::back() {
        check(0, "back on empty StrBlob");
        return data->back();
    }
    void StrBlob::pop_back() {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }
}

namespace Practise_12_01 {
    using namespace YH;
    void test() {
        StrBlob b1;
        {
            StrBlob b2 = { "a", "an", "the" };
            b1 = b2;
            b2.push_back("about");
        }
        cout << b1.size() << endl;
    }
}

namespace Practise_12_02 {
    class StrBolb {
        typedef vector<string> ::size_type size_type;
    private:
        shared_ptr<vector<string>> data;
        void check(size_type i, const string& msg) const {
            if (i >= data->size()) {
                throw out_of_range(msg);
            }
        }
    public:
        StrBolb() : data(make_shared<vector<string>>()) {}
        StrBolb(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
        void push_back(const string& s) {
            data->push_back(s);
        }
        void pop_back() {
            check(0 , "empty!");
            data->pop_back();
        }
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        string& front() {
            check(0, "empty front!");
            return data->front();
        }
        string& back() {
            check(0, "empty back!");
            return data->back();
        }
        const string& front() const {
            check(0, "empty const front");
            return data->front();
        }
        const string& back() const {
            check(0, "empty back front");
            return data->back();
        }
    };
}

namespace Practise_12_03 {
    class StrBlob {
        friend ostream& operator<<(ostream& os, const StrBlob& s);
    private:
        shared_ptr<vector<string>> data;
    public:
        StrBlob() : data(make_shared<vector<string>>()) {}
        StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
        void push_back(const string& s) const {
            data->push_back(s);
        }
        void pop_back() const {
            data->pop_back();
        }
    };
    ostream& operator<<(ostream& os, const StrBlob& s) {
        for (auto it = s.data->begin(); it != s.data->end(); ++it) {
            os << *it << " ";
        }
        return os;
    }
    void test() {
        StrBlob b = { "a", "b", "c" };
        b.push_back("d");
        cout << b << endl;
    }
}

namespace YH1 {
    void test() {
        const int *p = new const int();
        int *q = new (nothrow) int();
        cout << *p << endl;
        cout << *q << endl;
        delete q;
        delete p;
    }
}

namespace Practise_12_06 {
    void test1(vector<int> *);
    void test2(vector<int> *);
    void test() {
        vector<int> *vp = new vector<int>();
        test1(vp);
    }
    void test1(vector<int> *p) {
        int input;
        while (cin >> input && input != -1) {
            p->push_back(input);
        }
        test2(p);
    }
    void test2(vector<int> *p) {
        for (auto i : *p)
            cout << i << endl;
        delete p;
    }
}

namespace Practise_12_07 {
    void test1(shared_ptr<vector<int>> p);
    void test2(shared_ptr<vector<int>> p);
    void test() {
        shared_ptr<vector<int>> p = make_shared<vector<int>>();
        test1(p);
    }
    void test1(shared_ptr<vector<int>> p) {
        int input;
        while (cin >> input && input != -1) {
            p->push_back(input);
        }
        test2(p);
    }
    void test2(shared_ptr<vector<int>> p) {
        for (auto i : *p)
            cout << i << endl;
    }
}

namespace Practise_12_10 {
    void process(shared_ptr<int> p);
    void test() {
        shared_ptr<int> p(new int(10));
        cout << p.use_count() << endl;
        {
            process(shared_ptr<int> (p.get()));
            cout << p.use_count() << endl;
        }
        cout << p.use_count() << endl;
    }
    void process(shared_ptr<int> p) {
        cout << p.use_count() << endl;
    }
}

namespace Practise_12_12 {
    void process(shared_ptr<int> p) {
        
    }
    void test() {
        int *p = new int();
        process(shared_ptr<int> (p));
        delete p;  // double freed
    }
}

namespace Practise_12_13 {
    void test() {
        auto sp = make_shared<int>();
        auto p = sp.get();
        delete p;
    }
}

namespace Practise_12_14 {
    struct A {
        char *name;
        int id;
    };
    void destroy(A *a) {
        cout << "destroy" << endl;
    }
    void test() {
        {
            A a;
            shared_ptr<A> p(&a, destroy);
        }
        cout << "haha" << endl;
    }
}

namespace Practise_12_15 {
    void test() {
        
        unique_ptr<int> p(new int());
        unique_ptr<int> q;
        
        cout << *p << endl;
    }
}

namespace Practise_12_17 {
    void test() {
        
        int ix = 1024, *pi = &ix, *pi2 = new int(2048);
        
//        unique_ptr<int> p0(ix);
//        unique_ptr<int> p1(pi);
        unique_ptr<int> p2(pi2);
//        unique_ptr<int> p3(&ix);
        unique_ptr<int> p4(new int(2048));
//        unique_ptr<int> p5(p2.get());
        unique_ptr<int> p5(p2.release());
    }
}

namespace Practise_12_19 {
    class StrBlobPtr;
    /**
     *  StrBlobPtr
     */
    class StrBlob {
        friend class StrBlobPtr;
        friend ostream& operator<<(ostream& os, const StrBlob& s);
    public:
        typedef vector<string>::size_type size_type;
        StrBlob() : data(make_shared<vector<string>>()) {}
        StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
        StrBlobPtr begin();
        StrBlobPtr end();
        size_type size() { return data->size(); }
        bool empty() { return data->empty(); }
        void push_back(const string& s) {
            data->push_back(s);
        }
        void pop_back() {
            check(0, "pop_back from empty vector!");
            data->pop_back();
        }
        string& front() const {
            check(0, "front from empty vector!");
            return data->front();
        }
        string& back() const {
            check(0, "back from empty vector!");
            return data->back();
        }
    private:
        shared_ptr<vector<string>> data;
        void check(size_type i, const string& s) const {
            if (i >= data->size()) {
                throw out_of_range(s);
            }
        }
    };
    ostream& operator<<(ostream& os, const StrBlob& s) {
        for (auto i : *(s.data))
            os << i << " ";
        return os;
    }
    
    /**
     *  StrBlobPtr
     */
    class StrBlobPtr {
    public:
        StrBlobPtr() : curr(0) {}
        StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
        string& deref() const;
        StrBlobPtr& incr();
        bool operator==(const StrBlobPtr& b) {
            return curr == b.curr;
        }
        bool operator!=(const StrBlobPtr& b) {
            return !(*this == b);
        }
    private:
        shared_ptr<vector<string>> check(size_t, const string&) const;
        weak_ptr<vector<string>> wptr;
        size_t curr;
    };
    
    shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string & msg) const {
        auto ret = wptr.lock();
        if (!ret) {
            throw runtime_error("unbound StrBlobPtr!");
        }
        if (i >= ret->size()) {
            throw out_of_range(msg);
        }
        return ret;
    }
    string& StrBlobPtr::deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    StrBlobPtr& StrBlobPtr::incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
    
    /**
     *  StrBlob
     */
    StrBlobPtr StrBlob::begin() {
        return StrBlobPtr(*this);
    }
    StrBlobPtr StrBlob::end() {
        return StrBlobPtr(*this, data->size());
    }
    
    void test() {
        StrBlob b = { "a", "b", "c" };
        cout << b << endl;
    }
}

namespace Practise_12_20 {
    using namespace Practise_12_19;
    void test() {
        StrBlob s;
        string tmp;
        while (cin >> tmp && tmp != "end") {
            s.push_back(tmp);
        }
        for (StrBlobPtr b = s.begin(); b != s.end(); b.incr()) {
            cout << b.deref() << endl;
        }
    }
}

namespace Practise_12_21 {
    class StrVPtr;
    class ConstStrVPtr;
    class StrV {
        friend class StrVPtr;
        friend class ConstStrVPtr;
    public:
        typedef vector<string>::size_type size_type;
        
        // constructor
        StrV() : data(make_shared<vector<string>>()) {}
        StrV(initializer_list<string> il) : data(make_shared<vector<string>> (il)) {}
        
        // iterator
        StrVPtr begin();
        StrVPtr end();
        
        // const iterator
        ConstStrVPtr cbegin() const;
        ConstStrVPtr cend() const;
        
        bool empty() const { return data->empty(); }
        size_type size() const { return data->size(); }
        void push_back(const string& s) {
            data->push_back(s);
        }
        void pop_back() {
            check(0, "empty");
            data->pop_back();
        }
        string& front() const {
            check(0, "empty");
            return data->front();
        }
        string& back() const {
            check(0, "empty");
            return data->back();
        }
    private:
        shared_ptr<vector<string>> data;
        void check(size_type i, const string& m) const {
            if (i >= data->size()) {
                throw out_of_range(m);
            }
        }
    };
    
    class StrVPtr {
    public:
        StrVPtr(StrV& sv) : wptr(sv.data), cur(0) {}
        StrVPtr(StrV& sv, size_t sz) : wptr(sv.data), cur(sz) {}
        string& operator*(const StrVPtr& s) const {
            auto ret = check(cur, "haha");
            return (*ret)[cur];
        }
        bool operator==(const StrVPtr& s) {
            return cur == s.cur;
        }
        bool operator!=(const StrVPtr& s) {
            return !(*this == s);
        }
    private:
        size_t cur;
        weak_ptr<vector<string>> wptr;
        shared_ptr<vector<string>> check(size_t i, const string& msg) const {
            auto ret = wptr.lock();
            if (!ret) {
                throw runtime_error("NULL");
            }
            if (i >= ret->size()) {
                throw out_of_range(msg);
            }
            return ret;
        }
    };
    
    class ConstStrVPtr {
    public:
        ConstStrVPtr(const StrV& sv) : wptr(sv.data), cur(0) {}
        ConstStrVPtr(const StrV& sv, size_t sz) : wptr(sv.data), cur(sz) {}
        bool operator!=(const ConstStrVPtr& c) { return cur != c.cur; }
        ConstStrVPtr& operator++() {
            check(cur, "out of bounds");
            ++cur;
            return *this;
        }
        const string& operator*() const {
            auto ret = check(cur, "hehe");
            return (*ret)[cur];
        }
    private:
        weak_ptr<vector<string>> wptr;
        size_t cur;
        shared_ptr<vector<string>> check(size_t i, const string& msg) const {
            auto ret = wptr.lock();
            if (!ret) {
                throw runtime_error("hehe");
            }
            if (i >= ret->size()) {
                throw out_of_range(msg);
            }
            return ret;
        }
    };
    
    StrVPtr StrV::begin() {
        return StrVPtr(*this);
    }
    StrVPtr StrV::end() {
        return StrVPtr(*this, data->size());
    }
    ConstStrVPtr StrV::cbegin() const {
        return ConstStrVPtr(*this);
    }
    ConstStrVPtr StrV::cend() const {
        return ConstStrVPtr(*this, data->size());
    }
    
    void test() {
        const StrV sv = {"haha", "ljie", "yanghan"};
        for (ConstStrVPtr cb = sv.cbegin(); cb != sv.cend(); ++cb) {
            cout << *cb << endl;
        }
    }
}





int main(int argc, const char * argv[]) {
    
    Practise_12_21::test();
    
    return 0;
}
