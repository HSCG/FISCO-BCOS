#pragma once

#include "DB.h"

namespace dev {

namespace storage {

class TableData {
public:
	typedef std::shared_ptr<TableData> Ptr;

	std::string tableName;
	std::map<std::string, Entries::Ptr> data;
};

class Storage: public std::enable_shared_from_this<Storage> {
public:
	typedef std::shared_ptr<Storage> Ptr;

	virtual ~Storage() {};

	virtual TableInfo::Ptr info(const std::string &table) = 0;
	virtual Entries::Ptr select(h256 hash, int num, const std::string &table, const std::string &key) = 0;
	virtual size_t commit(h256 hash, int num, const std::vector<TableData::Ptr> &datas, h256 blockHash) = 0;
	virtual bool onlyDirty() = 0;
};

}

}