/*
 * Copyright 2014 Marios Kogias <marioskogias@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 *   1. Redistributions of source code must retain the above
 *      copyright notice, this list of conditions and the following
 *      disclaimer.
 *   2. Redistributions in binary form must reproduce the above
 *      copyright notice, this list of conditions and the following
 *      disclaimer in the documentation and/or other materials
 *      provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY COPYRIGHT HOLDERS ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include <ztracer.hpp>
#include <cstring>

namespace ZTracer {
	int ztrace_init(void)
	{
		return blkin_init();
	}

	ZTraceEndpointRef ZTraceEndpoint::create(const string &ip, int port, const string &name)
	{
		return shared_ptr<ZTraceEndpoint>(
				new ZTraceEndpoint(ip, port, name));
	}

	ZTraceRef ZTrace::create(const string &name, ZTraceEndpointRef ep)
	{
		return shared_ptr<ZTrace>(new ZTrace(name, ep));
	}

	ZTraceRef ZTrace::create(const string &name, ZTraceRef t)
	{
		return shared_ptr<ZTrace>(new ZTrace(name, t));
	}

	ZTraceRef ZTrace::create(const string &name, ZTraceRef t, ZTraceEndpointRef ep)
	{
		return shared_ptr<ZTrace>(new ZTrace(name, t, ep));
	}

	ZTraceRef ZTrace::create(const string &name, ZTraceEndpointRef ep, struct blkin_trace_info *info, bool child)
	{
		return shared_ptr<ZTrace>(new ZTrace(name, ep, info, child));
	}
	int ZTrace::get_trace_info(struct blkin_trace_info *info)
	{
		return blkin_get_trace_info(&trace, info);
	}
	int ZTrace::set_trace_info(struct blkin_trace_info *info)
	{
		return blkin_set_trace_info(&trace, info);
	}
}
