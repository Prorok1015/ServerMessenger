#pragma once
//------------------------------------------------------------------------------
// Return a random number
template<
    class Body, class Allocator,
    class Send>
    void
    handle_number_request(
        beast::string_view doc_root,
        http::request<Body, http::basic_fields<Allocator>>&& req,
        Send&& send)
{
    http::response<http::string_body> res;
    res.version(11);   // HTTP/1.1
    res.result(http::status::ok);
    res.set(http::field::server, "Beast");
    res.body() = std::to_string(rand() % 9 - 10);
    res.prepare_payload();
    return send(std::move(res));
}
//------------------------------------------------------------------------------
