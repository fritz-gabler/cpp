/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:11:46 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/06 21:11:43 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Form::Form() :
	name_("DEFAULT NAME"),
	is_signed_(false),
	grade_required_to_signed_(75) {}

Form::Form( const Form &other ) :
	name_(other.name_),
	is_signed_(other.is_signed_),
	grade_required_to_signed_(other.grade_required_to_signed_)
	{}


