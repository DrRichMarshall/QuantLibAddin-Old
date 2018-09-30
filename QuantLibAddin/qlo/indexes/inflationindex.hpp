/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2018 Richard Marshall

This file is part of QuantLib, a free-software/open-source library
for financial quantitative analysts and developers - http://quantlib.org/

QuantLib is free software: you can redistribute it and/or modify it
under the terms of the QuantLib license.  You should have received a
copy of the license along with this program; if not, please email
<quantlib-dev@lists.sf.net>. The license is also available online at
<http://quantlib.org/license.shtml>.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file inflationindex.hpp
    \brief base classes for inflation indexes
*/

#ifndef qla_inflation_index_hpp
#define qla_inflation_index_hpp

#include <qlo/index.hpp>

#include <ql/indexes/inflationindex.hpp>


namespace QuantLibAddin {

	//! Base class for zero inflation indices.
	class ZeroInflationIndex : public InflationIndex {
	public:
		//! Always use the evaluation date as the reference date
		ZeroInflationIndex(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			const std::string& familyName,
			const QuantLib::Region& region,
			bool revised,
			bool interpolated,
			QuantLib::Frequency& frequency,
			const QuantLib::Period& availabilitiyLag,
			const QuantLib::Currency& currency,
			const QuantLib::Handle<QuantLib::ZeroInflationTermStructure>& hZITS,
			bool permanent);
	protected:
		OH_OBJ_CTOR(ZeroInflationIndex, InflationIndex);
	};

	//! Base class for year-on-year inflation indices.
	class YoYInflationIndex : public InflationIndex {
	public:
		YoYInflationIndex(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			const std::string& familyName,
			const QuantLib::Region& region,
			bool revised,
			bool interpolated,
			bool ratio, // is this one a genuine index or a ratio?
			QuantLib::Frequency& frequency,
			const QuantLib::Period& availabilitiyLag,
			const QuantLib::Currency& currency,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& hYoYITS,
			bool permanent);
	protected:
		OH_OBJ_CTOR(YoYInflationIndex, InflationIndex)
	};
}

#endif
