#pragma once

/** 13.9 Write a smart pointer (smart_ptr) class. **/

struct Expression {
	Expression(int val)
		: value(val) { }
	void print() { cout << value << " "; }
private:
	int value;
};

struct SharedPtr
{

	explicit SharedPtr(Expression *ptr = 0)
	{
		info_ = new Info(ptr);
		if (info_->ptr_ != 0) {
			info_->counter++;
		}
	}
	~SharedPtr()
	{
		if (info_->ptr_ != 0) {
			info_->counter--;
			if (info_->counter == 0) {
				delete info_;
			}
		} else {
			delete info_;
		}
	}

	SharedPtr(const SharedPtr & sptr)
	{
		info_ = sptr.info_;
		if (info_->ptr_ != 0)
			info_->counter++;

	}
	SharedPtr& operator=(const SharedPtr & sptr)
	{
		if (this != &sptr) {
			if (info_->ptr_ != 0) {
				info_->counter--;
				if (info_->counter == 0) {
					delete info_;
					info_ = 0;
				}
				if (sptr.info_->ptr_ != 0) {
					info_ = sptr.info_;
					info_->counter++;
				} else {
					info_ = new Info(0);
				}
			} else {
				if (sptr.info_->ptr_ != 0) {
					delete info_;
					info_ = 0;
					info_ = sptr.info_;
					info_->counter++;
				}
			}
		}
		return *this;
	}
	Expression* get() const {
		return info_->ptr_;
	}
	void reset(Expression *ptr = 0) {
		if (info_->ptr_ != 0) {
			info_->counter--;
			if (info_->counter == 0) {
				delete info_;
				info_ = 0;
			}
		} else {
			delete info_;
			info_ = 0;
		}
		info_ = new Info(ptr);
		if (info_->ptr_ != 0)
			info_->counter = 1;
	}
	Expression& operator*() const
	{
		return *info_->ptr_;
	}
	Expression* operator->() const
	{
		return info_->ptr_;
	}
private:
	struct Info
	{
		Info(Expression* ptr)
			: counter(0)
			, ptr_(ptr) { }
		~Info()
		{
			if (ptr_ != 0)
				delete ptr_;
		}
		int counter;
		Expression* ptr_;
	};
	Info* info_;
};
